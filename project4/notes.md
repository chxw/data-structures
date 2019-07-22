** Insert in random order
insert 5

5
insert 2

5

          2
insert 1

5

          2

                    1
insert 4

5

                    4

          2

                    1
insert 6

          6

5

                    4

          2

                    1
insert 3

          6

5

                    4

                              3

          2

                    1
** Balance fcn:
before 

          6

5

                    4

                              3

          2

                    1
after 

                    6

          5

                    4

3

                    2

          1
** Delete in random order
delete 2

                    6

          5

                    4

3

          1
delete 1

                    6

          5

                    4

3
delete 6

          5

                    4

3
delete 3

5

          4
delete 5

4
delete 4
** Insert in order
insert 7

7
insert 8

          8

7
insert 9

                    9

          8

7
insert 10

                              10

                    9

          8

7
insert 11

                                        11

                              10

                    9

          8

7
insert 12

                                                  12

                                        11

                              10

                    9

          8

7
** Balance fcn:
before 

                                                  12

                                        11

                              10

                    9

          8

7
after 

                    12

          11

                    10

9

                    8

          7
** Delete in random order
delete 8

                    12

          11

                    10

9

          7
delete 9

                    12

          11

10

          7
delete 12

          11

10

          7
delete 11

10

          7
delete 10

7
delete 7
** Insert in random order
insert 18

18
insert 13

18

          13
insert 17

18

                    17

          13
insert 15

18

                    17

                              15

          13
insert 16

18

                    17

                                        16

                              15

          13
insert 14

18

                    17

                                        16

                              15

                                        14

          13
** Delete in order
delete 13

18

          17

                              16

                    15

                              14
delete 14

18

          17

                              16

                    15
delete 15

18

          17

                    16
delete 16

18

          17
delete 17

18
delete 18


--27118-- REDIR: 0x574f580 (libc.so.6:free) redirected to 0x4c2ac23 (free)
==27118== 
==27118== HEAP SUMMARY:
==27118==     in use at exit: 72,704 bytes in 1 blocks
==27118==   total heap usage: 42 allocs, 41 frees, 74,648 bytes allocated
==27118== 
==27118== Searching for pointers to 1 not-freed blocks
==27118== Checked 110,760 bytes
==27118== 
==27118== 72,704 bytes in 1 blocks are still reachable in loss record 1 of 1
==27118==    at 0x4C29B90: malloc (vg_replace_malloc.c:299)
==27118==    by 0x4EBF17F: pool (eh_alloc.cc:117)
==27118==    by 0x4EBF17F: __static_initialization_and_destruction_0 (eh_alloc.cc:244)
==27118==    by 0x4EBF17F: _GLOBAL__sub_I_eh_alloc.cc (eh_alloc.cc:307)
==27118==    by 0x400F8F2: call_init (dl-init.c:82)
==27118==    by 0x400F8F2: _dl_init (dl-init.c:131)
==27118==    by 0x4001159: ??? (in /usr/lib64/ld-2.17.so)
==27118== 
==27118== LEAK SUMMARY:
==27118==    definitely lost: 0 bytes in 0 blocks
==27118==    indirectly lost: 0 bytes in 0 blocks
==27118==      possibly lost: 0 bytes in 0 blocks
==27118==    still reachable: 72,704 bytes in 1 blocks
==27118==         suppressed: 0 bytes in 0 blocks
==27118== 
==27118== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 6 from 6)
--27118-- 
--27118-- used_suppression:      6 dl-hack3-cond-1 /usr/sup/valgrind-3.11.0/lib/valgrind/default.supp:1218
==27118== 
==27118== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 6 from 6)
