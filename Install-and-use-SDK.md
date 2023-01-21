# Install SDK:

1. unzip the sdk
2. run  ```./sdk.unpack```
    * make shure the file is executable. maybe change the shell from sh to bash and insert a "./" in the source command
3. install the crosscompiler:
    1. goto osdrv/toolchain/arm-hisiv100nptl-linux
    2. ```chmod +x cross.install``` 
    3. ```./cross.install```
    4. logout & login again (otherwise the path is not properly set)
4. To build the binaries: within the osdrv folder execute: ```make OSDRV_CROSS=arm-hisiv100nptl-linux CHIP=hi3518c SHELL=/bin/bash all```

# build 

## build hello world: 
```arm-hisiv100nptl-linux-gcc hello.c -o hello-arm```

## build socat

``` 
./configure --host=amd64 --build=armv5te_soft CC=arm-hisiv100nptl-linux-gcc

``` 

### 

```shell
# make directory
mkdir temp
# mount temp filesystem:
mount -t tmpfs -o size=300k none temp
cd temp

#download file via http server:
wget http://192.168.0.123/socat
#make executable: 
chmod +x socat

# sample call:
./socat -t100 -x -v UNIX-LISTEN:/tmp/msg_snap_request,mode=777,reuseaddr,fork UNIX-CONNECT:/tmp/msg_snap_request.orig
```

## build strace
```
./configure --host=armv5 CC=arm-hisiv100nptl-linux-gcc
```

### use strace
```
./strace -f -e 'trace=!nanosleep,select' webs

```