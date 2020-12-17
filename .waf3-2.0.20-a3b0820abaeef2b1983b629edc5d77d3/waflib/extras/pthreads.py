#! /usr/bin/env python
# encoding: utf-8
# WARNING! Do not edit! https://waf.io/book/index.html#_obtaining_the_waf_file

#!/usr/bin/env python
# encoding: utf-8
#
# partially based on boost.py written by Gernot Vormayr
# written by Ruediger Sonderfeld <ruediger@c-plusplus.de>, 2008
# modified by Bjoern Michaelsen, 2008
# modified by Luca Fossati, 2008
# rewritten for waf 1.5.1, Thomas Nagy, 2008
# rewritten for waf 1.6.2, Sylvain Rouquette, 2011
# split from boost.py to pthreads.py, Alibek Omarov, 2019

'''

This is an extra tool, not bundled with the default waf binary.
To add the boost tool to the waf file:
$ ./waf-light --tools=pthreads

When using this tool, the wscript will look like:
	def configure(conf):
		conf.load('compiler_cxx pthreads')
		conf.check_pthread_flag()

	def build(bld):
		bld(source='main.cpp', target='app', use='PTHREAD')
'''

from waflib import Utils
from waflib.Configure import conf

PTHREAD_CODE = '''
#include <pthread.h>
static void* f(void* unused) {
	(void)(unused);
	return 0;
}

int main() {
	pthread_t th;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&th, &attr, &f, 0);
	pthread_join(th, 0);
	pthread_cleanup_push(0, 0);
	pthread_cleanup_pop(0);
	pthread_attr_destroy(&attr);
}
'''

@conf
def check_pthread_flag(self, *k, **kw):
	'''
	Computes which flags should be added to CXXFLAGS and LINKFLAGS to compile in multi-threading mode

	Yes, we *need* to put the -pthread thing in CPPFLAGS because with GCC3,
	boost/thread.hpp will trigger a #error if -pthread isn't used:
	  boost/config/requires_threads.hpp:47:5: #error "Compiler threading support
	  is not turned on. Please set the correct command line options for
	  threading: -pthread (Linux), -pthreads (Solaris) or -mthreads (Mingw32)"

	Based on _BOOST_PTHREAD_FLAG(): https://github.com/tsuna/boost.m4/blob/master/build-aux/boost.m4
    '''

	var = kw.get('uselib_store', 'PTHREAD')

	self.start_msg('Checking the flags needed to use pthreads')

	# The ordering *is* (sometimes) important.  Some notes on the
	# individual items follow:
	# (none): in case threads are in libc; should be tried before -Kthread and
	#       other compiler flags to prevent continual compiler warnings
	# -lpthreads: AIX (must check this before -lpthread)
	# -Kthread: Sequent (threads in libc, but -Kthread needed for pthread.h)
	# -kthread: FreeBSD kernel threads (preferred to -pthread since SMP-able)
	# -llthread: LinuxThreads port on FreeBSD (also preferred to -pthread)
	# -pthread: GNU Linux/GCC (kernel threads), BSD/GCC (userland threads)
	# -pthreads: Solaris/GCC
	# -mthreads: MinGW32/GCC, Lynx/GCC
	# -mt: Sun Workshop C (may only link SunOS threads [-lthread], but it
	#      doesn't hurt to check since this sometimes defines pthreads too;
	#      also defines -D_REENTRANT)
	#      ... -mt is also the pthreads flag for HP/aCC
	# -lpthread: GNU Linux, etc.
	# --thread-safe: KAI C++
	if Utils.unversioned_sys_platform() == "sunos":
		# On Solaris (at least, for some versions), libc contains stubbed
		# (non-functional) versions of the pthreads routines, so link-based
		# tests will erroneously succeed.  (We need to link with -pthreads/-mt/
		# -lpthread.)  (The stubs are missing pthread_cleanup_push, or rather
		# a function called by this macro, so we could check for that, but
		# who knows whether they'll stub that too in a future libc.)  So,
		# we'll just look for -pthreads and -lpthread first:
		boost_pthread_flags = ["-pthreads", "-lpthread", "-mt", "-pthread"]
	else:
		boost_pthread_flags = ["", "-lpthreads", "-Kthread", "-kthread", "-llthread", "-pthread",
							   "-pthreads", "-mthreads", "-lpthread", "--thread-safe", "-mt"]

	for boost_pthread_flag in boost_pthread_flags:
		try:
			self.env.stash()
			self.env.append_value('CFLAGS_%s' % var, boost_pthread_flag)
			self.env.append_value('CXXFLAGS_%s' % var, boost_pthread_flag)
			self.env.append_value('LINKFLAGS_%s' % var, boost_pthread_flag)
			self.check_cxx(code=PTHREAD_CODE, msg=None, use=var, execute=False)

			self.end_msg(boost_pthread_flag)
			return
		except self.errors.ConfigurationError:
			self.env.revert()
	self.end_msg('None')
