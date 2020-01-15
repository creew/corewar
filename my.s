.name "zork"
.comment "Hello

net
work
qq
laptev



"
l2:
		sti r99,%:live,%1
		and r99,%0,r99
live:   live %1
		zjmp %:live
