README
======

- Get CO2
```console
$ dbus-send --system --dest=iot.service.rpmsg --print-reply --type=method_call / local.ServiceRPMSG.CRpmsgInterface.getCO2
method return time=1508787942.168835 sender=:1.5 -> destination=:1.55 serial=52 reply_serial=2
   uint32 565
```

- Get TVOC
```console
$ dbus-send --system --dest=iot.service.rpmsg --print-reply --type=method_call / local.ServiceRPMSG.CRpmsgInterface.getTVOC
method return time=1508787923.479148 sender=:1.5 -> destination=:1.28 serial=25 reply_serial=2
   uint32 149
```

- Get Status
```console
$ dbus-send --system --dest=iot.service.rpmsg --print-reply --type=method_call / local.ServiceRPMSG.CRpmsgInterface.getStatus
method return time=1508788204.349156 sender=:1.5 -> destination=:1.87 serial=84 reply_serial=2
   uint32 0
```

- Set LED
```console
$ dbus-send --system --dest=iot.service.rpmsg --print-reply --type=method_call / local.ServiceRPMSG.CRpmsgInterface.setLed boolean:true

```
