# OpenIPC Installation:

there are some little differences to the original open IPC Firmware, so the modified installation is documented here:

## Backup of Firmware:

Enter commands line by line! Do not copy and paste multiple lines at once!
```
setenv ipaddr 192.168.20.80; setenv serverip 192.168.20.169
mw.b 0x82000000 ff 0x800000; sf probe 0; sf read 0x82000000 0x0 0x800000

# tftpput 0x82000000 0x8000000 backup-hi3518ev100-nor8m.bin // this does not work with the stock bootloader! 
```

tftp put is not available on the stock u-boot, so instead use the following command:

```
tftp 0x82000000 backup.bin 0x800000
```

this should then look like this:

```
JUHUA # 
Hisilicon ETH net controler
miiphy_register: non unique device name '0:1'
miiphy_register: non unique device name '0:2'
MAC:   00-00-23-34-45-66
UP_PORT : phy status change : LINK=UP : DUPLEX=FULL : SPEED=100M
TFTP to server 192.168.20.169; our IP address is 192.168.20.80
Upload Filename 'backup.bin'.
Upload from address: 0x82000000, 8.000 MB to be send ...
Uploading: #    [ Connected ]
################################        [ 2.888 MB]
################################        [ 5.752 MB]
#########################
		 8.000 MB upload ok.
```


## Install new U-Boot


### install the new uboot
```
setenv ipaddr 192.168.20.80; setenv serverip 192.168.20.169
mw.b 0x82000000 ff 0x50000; tftp 0x82000000 u-boot-hi3518ev100-universal.bin
sf probe 0; sf erase 0x0 0x50000; sf write 0x82000000 0x0 0x50000
reset
```

```
JUHUA # setenv ipaddr 192.168.20.80; setenv serverip 192.168.20.169
JUHUA # mw.b 0x82000000 ff 0x50000; tftpboot 0x82000000 u-boot-hi3518ev100-universal.bin
Unknown command 'tftpboot' - try 'help'
JUHUA # mw.b 0x82000000 ff 0x50000; tftp 0x82000000 u-boot-hi3518ev100-universal.bin
Hisilicon ETH net controler
miiphy_register: non unique device name '0:1'
miiphy_register: non unique device name '0:2'
MAC:   00-00-23-34-45-66
UP_PORT : phy status change : LINK=UP : DUPLEX=FULL : SPEED=100M
TFTP from server 192.168.20.169; our IP address is 192.168.20.80
Download Filename 'u-boot-hi3518ev100-universal.bin'.
Download to address: 0x82000000
Downloading: #################################################
done
Bytes transferred = 182580 (2c934 hex)
JUHUA # sf probe 0; sf erase 0x0 0x50000; sf write 0x82000000 0x0 0x50000
8192 KiB hi_sfc at 0:0 is now current device
Erasing at 0x50000 -- 100% complete.
Writing at 0x50000 -- 100% complete.
JUHUA #
```

now you can continue with the original installation process:
```
run setnor8m
```
system will reboot
```
setenv ipaddr 192.168.20.80; setenv serverip 192.168.20.169
setenv ethaddr 00:11:22:33:44:55
saveenv
run uknor8m; run urnor8m
sf erase 0x750000 0xb0000
reset

```


now the system should start into linux but the network is not working.
On this specific camera the following settings have to be made:
```
fw_setenv extras 'hieth.mdioifu=0 hieth.mdioifd=0' && reboot
```


## Pin settings for Night Mode:

| Description in OpenIPC | Pin |
|--|--|
|GPIO pin1 of signal for IRcut filter | 20 |
|GPIO pin2 of signal for IRcut filter | 19 |
|GPIO pin to turn on night mode illumination | 42 |


