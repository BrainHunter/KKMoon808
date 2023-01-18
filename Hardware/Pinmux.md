
# PinMux

| Muxreg | PIN mux | Hardware |	GPIO | command|
|--|--|--|--|--|
|0	|Shuter Trig	     |
|1	|SDIO_CCLK_OUT	     |
|2	|SENSOR_CLK	         |
|3	|GPIO1_4	         | in	|12 | ./himd.l 0x201503FC 16|
|4	|GPIO1_5	         | in	|13
|5	|GPIO1_6	         | in	|14
|6	|I2C_SDA	         |
|7	|I2C_SCL	         |
|8	|UART1_RTSN	         |
|9	|GPIO2_3	         | out /  move IR Cut in | 19 | himm 0x20160020 0x8 &&  himm 0x20160020 0
|10	|GPIO2_4	         | out /  move IR Cut out | 20 | himm 0x20160040 0x10 &&  himm 0x20160040 0
|11	|GPIO2_5	         | out
|12	|MII_CRS	         |
|13	|MII_COL	         |
|14	|MII_RXD3	         |
|15	|MII_RXD2	         |
|16	|MII_RXD1	         |
|17	|MII_RXD0	         |
|18	|MII_TXD3	         |
|19	|MII_TXD2	         |
|20	|MII_TXD1	         |
|21	|MII_TXD0	         |
|22	|MII_RXCK	         |
|23	|MII_TXCK	         |
|24	|MII_RXDV	         |
|25	|MII_TXEN	         |
|26	|MII_TXER	         |
|27	|MII_RXER	         |
|28	|EPHY_CLK	         |
|29	|MDCK	             |
|30	|MDIO	             |
|31	|FLASH_TRIG	         |
|32	|SDIO_CARD_DETECT	 |
|33	|SDIO_CARD_POWER_EN	 |
|34	|SDIO_CWPR	         |
|35	|SDIO_CCMD	         |
|36	|SDIO_CDATA0	     |
|37	|SDIO_CDATA1	     |
|38	|SDIO_CDATA2	     |
|39	|SDIO_CDATA3	     |
|40	|SFC_DIO	         | Serial Flash Controller
|41	|SFC_WP_IO2	         |
|42	|SFC_CLK	         |
|43	|SFC_DOI	         |
|44	|SFC_HOLD_IO3	     |
|45	|GPIO5_0	         | out	| 40  	| himm 0x20190004 1
|46	|GPIO5_1	         | out	| 41	| himm 0x20190008 2
|47	|GPIO5_2	         | IR LED out | 42 |(#himm 0x20190010 0 #himm 0x20190010 4) (can be muxed to pwm_out0)
|48	|PWM_OUT1	         |
|49	|GPIO7_5	         | in	| 61 | ./himd.l 0x201B03FC 16|
|50	|GPIO9_0	         | Stepper Motor LR
|51	|GPIO9_1	         | Stepper Motor LR
|52	|GPIO9_2             | Stepper Motor LR
|53	|GPIO9_3             | Stepper Motor LR
|54	|GPIO9_4             | Stepper Motor UD
|55	|GPIO9_5             | Stepper Motor UD
|56	|GPIO9_6             | Stepper Motor UD
|57	|GPIO9_7             | Stepper Motor UD
|58	|GPIO8_0	         | in	| 64 | ./himd.l 0x201C03FC 16
|59	|GPIO8_1	         | in	| 65
|60	|NF_BOOT_PIN0	     |
|61	|GPIO8_3	         | in	| 66
|62	|GPIO8_4	         | in 	| 67
|63	|NF_BOOT_PIN1	     |
|64	|NF_ALE	             |
|65	|NF_WEN	             |
|66	|GPIO7_6	         | out | 62
|67	|GPIO7_7	         | in Reset Button (active low) | 63
|68	|GPIO5_4	         | in | 44 |(#./himd.l 0x20190010 16)
|69	|GPIO5_5	         | in | 45
|70	|GPIO5_6	         | in | 46
|71	|GPIO5_7	         | in | 47
|72	|GPIO0_0	         | out | 0
|73	|JTAG_TCK	         |
|74	|GPIO0_2	         | in | 2 | ./himd.l 0x201403FC 16
|75	|TAG_TDO	         |
|76	|GPIO0_4	         | in
|77	|GPIO0_5	         | out
|78	|SVB_PWM	         | ??? what is this
|79	|SYS_RSTN_OUT	     |
|80	|VIU_CLK	         |
|81	|VIU_VS	             |
|82	|VIU_HS	             |
|83	|VIU_DAT11	         |
|84	|VIU_DAT10	         |
|85	|VIU_DAT9	         |
|86	|VIU_DAT8	         |
|87	|VIU_DAT7	         |
|88	|VIU_DAT6	         |
|89	|VIU_DAT5	         |
|90	|VIU_DAT4	         |
|91	|VIU_DAT3	         |
|92	|VIU_DAT2	         |
|93	|VIU_DAT1	         |
|94	|VIU_DAT0	         |

# Registers


|Register | Base Addr |
|---|---|
|GPIO11 | 0x201F_0000 | 
|GPIO10 | 0x201E_0000 |
|GPIO9  | 0x201D_0000 |
|GPIO8  | 0x201C_0000 |
|GPIO7  | 0x201B_0000 |
|GPIO6  | 0x201A_0000 |
|GPIO5  | 0x2019_0000 |
|GPIO4  | 0x2018_0000 |
|GPIO3  | 0x2017_0000 |
|GPIO2  | 0x2016_0000 |
|GPIO1  | 0x2015_0000 |
|GPIO0  | 0x2014_0000 |

## Register Offsets

| Offset Address | Register | Description|
|--|--|--|--|
|0x000–0x3FC | GPIO_DATA 	|GPIO data register |
|0x400| GPIO_DIR 			|GPIO direction control register |
|0x404| GPIO_IS 			|GPIO interrupt trigger register |
|0x408| GPIO_IBE 			|GPIO interrupt dual-edge trigger register  |
|0x40C| GPIO_IEV 			|GPIO interrupt trigger event register |
|0x410| GPIO_IE 			|GPIO interrupt mask register |
|0x414| GPIO_RIS 			|GPIO raw interrupt status register |
|0x418| GPIO_MIS 			|GPIO masked interrupt status register |
|0x41C| GPIO_IC 			|GPIO interrupt clear register |

## Register readout

```console

# ln -s /rom/app/bin/btools himd.l
# ./himd.l 0x200F0000
*** Board tools : ver0.0.1_20121120 ***
[debug]: {source/utils/cmdshell.c:166}cmdstr:himd.l
====dump memory 0x200F0000====
0000:  00000001 00000001 00000001 00000000
0010:  00000000 00000000 00000001 00000001
0020:  00000001 00000000 00000000 00000000
0030:  00000001 00000001 00000001 00000001
0040:  00000001 00000001 00000001 00000001
0050:  00000001 00000001 00000001 00000001
0060:  00000001 00000001 00000001 00000001
0070:  00000001 00000001 00000001 00000001
0080:  00000001 00000001 00000001 00000001
0090:  00000001 00000001 00000001 00000001
00a0:  00000000 00000000 00000000 00000000
00b0:  00000000 00000000 00000000 00000000
00c0:  00000001 00000001 00000001 00000001
00d0:  00000001 00000001 00000001 00000001
00e0:  00000001 00000001 00000001 00000001
00f0:  00000002 00000001 00000001 00000002
[END]
# ./himd.l 0x200F0100
*** Board tools : ver0.0.1_20121120 ***
[debug]: {source/utils/cmdshell.c:166}cmdstr:himd.l
====dump memory 0x200F0100====
0000:  00000000 00000000 00000000 00000000
0010:  00000000 00000000 00000000 00000000
0020:  00000000 00000001 00000000 00000001
0030:  00000000 00000001 00000001 00000000
0040:  00000000 00000000 00000000 00000000
0050:  00000000 00000000 00000000 00000000
0060:  00000000 00000000 00000000 00000000
0070:  00000000 00000000 00000000 00000000
0080:  00000000 00000000 00000000 00000000
0090:  00000000 00000000 00000000 00000000
00a0:  00000000 00000000 00000000 00000000
00b0:  00000000 00000000 00000000 00000000
00c0:  00000000 00000000 00000000 00000000
00d0:  00000000 00000000 00000000 00000000
00e0:  00000000 00000000 00000000 00000000
00f0:  00000000 00000000 00000000 00000000
[END]

```


#ADC
Channel 0 is most likely conneced to the light sensor

Light  on the sensor:
```
# ./himd.l 0x200B0000 32
*** Board tools : ver0.0.1_20121120 ***
[debug]: {source/utils/cmdshell.c:166}cmdstr:himd.l
====dump memory 0x200B0000====
0000:  00000001 00000000 00000000 00000000
0010:  00000000 00000000 00000000 00000353
[END]
```

Sensor covered: 
```
# ./himd.l 0x200B0000 32
*** Board tools : ver0.0.1_20121120 ***
[debug]: {source/utils/cmdshell.c:166}cmdstr:himd.l
====dump memory 0x200B0000====
0000:  00000001 00000000 00000000 00000000
0010:  00000000 00000000 00000000 000002bf
[END]
```




### find out ir cut filter:
```
while [ 1 == 1 ]
do
./himd.l 0x201603FC 16 | grep 00000000
done
```
