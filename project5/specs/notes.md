## 8/2/19 Fri. : doubly linked lists, polynomial hasher
### Runtime:
13.756u 2.845s 0:17.35 95.6%	0+0k 89312+0io 0pf+0 
### Collision testing:
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 2736
### Duration:
dataset_small: 2542736 microseconds
dataset_large: 37495118 microseconds

## Unsigned int, base = 33
### Collision testing
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 60
### Duration
4.038u 0.099s 0:04.14 99.5%	0+0k 0+0io 0pf+0w

## int + user-designed mod, base = 33
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 2736

## Unsigned int, base = 37
### Collision testing
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 67
### Duration
4.024u 0.103s 0:04.13 99.7%	0+0k 0+0io 0pf+0w

## Unsigned int, base 64
### Collision testing
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 24341
### Duration
319.684u 0.188s 5:19.88 99.9%	0+0k 0+0io 0pf+0w

## Unsigned int, base 3
### Collision testing
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 66
### Duration
4.030u 0.108s 0:04.14 99.7%	0+0k 0+0io 0pf+0w

## Unsigned int, base 2
### Collision testing
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 146
### Duration
4.474u 0.104s 0:04.73 96.6%	0+0k 6808+0io 3pf+0w

## Unsigned int, base 1
### Collision testing
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 1311
### Duration
54.316u 0.124s 0:54.45 99.9%	0+0k 0+0io 0pf+0w

## Unsigned int, base random large prime number
### Collision testing
The number of buckets: 16384
The total number of items: 479828
The length of the longest chain (score): 6069
### Duration
18.326u 0.115s 0:18.48 99.7%	0+0k 0+0io 0pf+0w
