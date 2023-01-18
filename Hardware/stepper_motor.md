# Stepper Motor Control within the original Firmware

Info got from strace: 

```
open("/dev/gpio_drv", O_RDONLY) = 16

[pid  1957] ioctl(16, _IOC(0, 0x00, 0x0e, 0x00), 0x43273ea8) = 0
[pid  1957] ioctl(16, _IOC(0, 0x00, 0x8a, 0x00), 0) = 0

When goning to reference we something like this: 
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x90, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x9a, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x97, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x94, 0x00), 0) = 0
[pid  1952] nanosleep({0, 5000000},  <unfinished ...>
[pid  1952] <... nanosleep resumed> NULL) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x90, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x99, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x97, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x94, 0x00), 0) = 0
[pid  1952] nanosleep({0, 5000000},  <unfinished ...>
[pid  1952] <... nanosleep resumed> NULL) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x91, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x99, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x97, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x94, 0x00), 0) = 0
[pid  1952] nanosleep({0, 5000000},  <unfinished ...>
[pid  1952] <... nanosleep resumed> NULL) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x91, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x99, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x96, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x94, 0x00), 0) = 0
[pid  1952] nanosleep({0, 5000000},  <unfinished ...>
[pid  1952] <... nanosleep resumed> NULL) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x91, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x9a, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x96, 0x00), 0) = 0
[pid  1952] ioctl(16, _IOC(0, 0x00, 0x94, 0x00), 0) = 0
...
END Reference


```


## going up:
```

pid  1318] accept(17, {sa_family=AF_INET, sin_port=htons(61977), sin_addr=inet_addr("192.168.20.53")}, [16]) = 18
[pid  1318] fcntl64(18, F_SETFD, FD_CLOEXEC) = 0
[pid  1318] fcntl64(18, F_GETFL)        = 0x2 (flags O_RDWR)
[pid  1318] fcntl64(18, F_SETFL, O_RDWR|O_NONBLOCK) = 0
[pid  1318] gettimeofday({1673779374, 417020}, NULL) = 0
[pid  1318] gettimeofday({1673779374, 420625}, NULL) = 0
[pid  1318] select(19, [17 18], [], [], {1, 0}) = 1 (in [18], left {0, 999954})
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1318] gettimeofday( <unfinished ...>
[pid  1319] <... select resumed> )      = 0 (Timeout)
[pid  1319] select(14, [13], NULL, NULL, {0, 200000} <unfinished ...>
[pid  1318] <... gettimeofday resumed> {1673779374, 428715}, NULL) = 0
[pid  1318] recv(18, "GET /goform/ptz.cgi?action=2&spe"..., 2047, 0) = 188
[pid  1318] write(1, "ptz action 1 PresetName 0 Speed "..., 45ptz action 1 PresetName 0 Speed 0 StepSize 0
) = 45
[pid  1318] send(18, "HTTP/1.0 200 OK\r\nContent-Type: t"..., 48, 0) = 48
[pid  1318] fcntl64(18, F_GETFL)        = 0x802 (flags O_RDWR|O_NONBLOCK)
[pid  1318] fcntl64(18, F_SETFL, O_RDWR) = 0
[pid  1318] fcntl64(18, F_GETFL)        = 0x2 (flags O_RDWR)
[pid  1318] fcntl64(18, F_SETFL, O_RDWR|O_NONBLOCK) = 0
[pid  1318] shutdown(18, SHUT_WR)       = 0
[pid  1318] recv(18, "", 256, 0)        = 0
[pid  1318] close(18)                   = 0
[pid  1318] select(18, [17], [], [], {1, 0} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1323] select(16, [15], NULL, NULL, {0, 0}) = 0 (Timeout)
[pid  1323] ioctl(16, _IOC(0, 0x00, 0x0e, 0x00), 0x43264ea8) = 0
[pid  1323] rt_sigaction(SIGCHLD, NULL, {SIG_DFL, [], 0}, 8) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1319] <... select resumed> )      = 0 (Timeout)
[pid  1319] select(14, [13], NULL, NULL, {0, 200000} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1322] <... select resumed> )      = 0 (Timeout)
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1322] select(15, [14], NULL, NULL, {1, 0} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1319] <... select resumed> )      = 0 (Timeout)
[pid  1319] select(14, [13], NULL, NULL, {0, 200000} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00) <unfinished ...>
[pid  1348] rt_sigaction(SIGCHLD, NULL, {SIG_DFL, [], 0}, 8) = 0
[pid  1347] <... ioctl resumed> , 0)    = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1318] <... select resumed> )      = 1 (in [17], left {0, 457966})
[pid  1318] accept(17,  <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1318] <... accept resumed> {sa_family=AF_INET, sin_port=htons(61978), sin_addr=inet_addr("192.168.20.53")}, [16]) = 18
[pid  1318] fcntl64(18, F_SETFD, FD_CLOEXEC) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1318] fcntl64(18, F_GETFL)        = 0x2 (flags O_RDWR)
[pid  1318] fcntl64(18, F_SETFL, O_RDWR|O_NONBLOCK) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9f, 0x00), 0) = 0
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1319] <... select resumed> )      = 0 (Timeout)
[pid  1319] select(14, [13], NULL, NULL, {0, 200000} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1318] gettimeofday({1673779375, 103537}, NULL) = 0
[pid  1318] gettimeofday({1673779375, 105679}, NULL) = 0
[pid  1318] select(19, [17 18], [], [], {1, 0} <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa2, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1318] <... select resumed> )      = 1 (in [18], left {0, 999940})
[pid  1318] gettimeofday({1673779375, 129069}, NULL) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1318] recv(18, "GET /goform/ptz.cgi?action=0&spe"..., 2047, 0) = 188
[pid  1318] write(1, "ptz action 0 PresetName 0 Speed "..., 45ptz action 0 PresetName 0 Speed 0 StepSize 0
 <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa5, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1318] <... write resumed> )       = 45
[pid  1318] send(18, "HTTP/1.0 200 OK\r\nContent-Type: t"..., 48, 0) = 48
[pid  1318] fcntl64(18, F_GETFL <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9c, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1318] <... fcntl64 resumed> )     = 0x802 (flags O_RDWR|O_NONBLOCK)
[pid  1318] fcntl64(18, F_SETFL, O_RDWR <unfinished ...>
[pid  1347] ioctl(16, _IOC(0, 0x00, 0x9d, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa0, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa3, 0x00), 0) = 0
[pid  1347] ioctl(16, _IOC(0, 0x00, 0xa6, 0x00), 0) = 0
[pid  1321] <... select resumed> )      = 0 (Timeout)
[pid  1321] select(1, [], NULL, NULL, {0, 100000} <unfinished ...>
[pid  1318] <... fcntl64 resumed> )     = 0
[pid  1318] fcntl64(18, F_GETFL)        = 0x2 (flags O_RDWR)
[pid  1318] fcntl64(18, F_SETFL, O_RDWR|O_NONBLOCK) = 0
[pid  1318] shutdown(18, SHUT_WR)       = 0
[pid  1318] recv(18, "", 256, 0)        = 0
[pid  1318] close(18)                   = 0

```