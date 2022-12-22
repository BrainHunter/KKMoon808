
# PinMux

| Muxreg | PIN mux | Hardware |
|--|--|--|
|0	|Shuter Trig	     |
|1	|SDIO_CCLK_OUT	     |
|2	|SENSOR_CLK	         |
|3	|GPIO1_4	         |
|4	|GPIO1_5	         |
|5	|GPIO1_6	         |
|6	|I2C_SDA	         |
|7	|I2C_SCL	         |
|8	|UART1_RTSN	         |
|9	|GPIO2_3	         |
|10	|GPIO2_4	         |
|11	|GPIO2_5	         |
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
|40	|SFC_DIO	         |
|41	|SFC_WP_IO2	         |
|42	|SFC_CLK	         |
|43	|SFC_DOI	         |
|44	|SFC_HOLD_IO3	     |
|45	|GPIO5_0	         |
|46	|GPIO5_1	         |
|47	|GPIO5_2	         |
|48	|PWM_OUT1	         |
|49	|GPIO7_5	         |
|50	|GPIO9_0	         | Stepper Motor LR
|51	|GPIO9_1	         | Stepper Motor LR
|52	|GPIO9_2             | Stepper Motor LR
|53	|GPIO9_3             | Stepper Motor LR
|54	|GPIO9_4             | Stepper Motor UD
|55	|GPIO9_5             | Stepper Motor UD
|56	|GPIO9_6             | Stepper Motor UD
|57	|GPIO9_7             | Stepper Motor UD
|58	|GPIO8_0	         |
|59	|GPIO8_1	         |
|60	|NF_BOOT_PIN0	     |
|61	|GPIO8_3	         |
|62	|GPIO8_4	         |
|63	|NF_BOOT_PIN1	     |
|64	|NF_ALE	             |
|65	|NF_WEN	             |
|66	|GPIO7_6	         |
|67	|GPIO7_7	         |
|68	|GPIO5_4	         |
|69	|GPIO5_5	         |
|70	|GPIO5_6	         |
|71	|GPIO5_7	         |
|72	|GPIO0_0	         |
|73	|JTAG_TCK	         |
|74	|GPIO0_2	         |
|75	|TAG_TDO	         |
|76	|GPIO0_4	         |
|77	|GPIO0_5	         |
|78	|SVB_PWM	         |
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

