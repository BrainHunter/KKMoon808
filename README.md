# KKMoon808
Analysis of a KKMoon 808 Ip Camera

this Repo is to store all information gathered from analyzing the camera 

## Status
The Camera works with the app  (well it did back in the time, not tested since years)
Problem with the app is that it is with some unencrypted china p2p system. it will transfer your wifi password unencrypted all through the internets ;-)

There is a "webserver"... maybe this works on older systems. maybe one should try...

rtsp stream is available and can be received via vlc. This is not very stable and will crash 
after restart of the application on the system the camera lost its stepper possitions thus rotating in one direction. so this is not very usefull.



things may not be described here but will may be documented some day

* linux root access
* enabled telnet
* how to modify the filesystem
* 
* Bootloader is accessable (password is "*****")  
* rtsp stream
* get still images via http
* http control protocol + programm to control it
* control stepper directly via console
* cross compile tools to run on the original firmware [Link](Install-and-use-SDK.md)
* [installation of openIPC](openIPC/install.md)


## Open topics 
**but most likely are never answered since openipc is runnig.**
* why is the app crashing when accessing the rtsp stream
* build a kernel 
