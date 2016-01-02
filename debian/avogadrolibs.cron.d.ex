#
# Regular cron jobs for the avogadrolibs package
#
0 4	* * *	root	[ -x /usr/bin/avogadrolibs_maintenance ] && /usr/bin/avogadrolibs_maintenance
