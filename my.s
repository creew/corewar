.name "zork"
.comment "Hello network"
l2:
		sti r101,%:live,%1
		and r99,%0,r99
live:   live %1
		zjmp %:live