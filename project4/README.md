http://web.eecs.umich.edu/~qstout/pap/CACM86.pdf
http://www.cs.ecu.edu/karl/3300/spr16/Notes/DataStructure/Tree/balance.html


*Learned how to use lldb*
```
Process 85704 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x0)
    frame #0: 0x000000010000283c test`Student::getID() const + 12
test`Student::getID:
->  0x10000283c <+12>: movl   (%rdi), %eax
    0x10000283e <+14>: popq   %rbp
    0x10000283f <+15>: retq   

test`Student::getFirstName:
    0x100002840 <+0>:  pushq  %rbp
Target 0: (test) stopped.
```
