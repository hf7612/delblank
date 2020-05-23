// #include
// int
// main(int argc, char *argv[])
// {
//   int sim_fd;
//   int x, y;
//   char buffer[10];
//   /* Open the sysfs coordinate node */
//   sim_fd = open("/sys/devices/platform/vms/coordinates", O_RDWR);
//   if (sim_fd < 0) {
//     perror("Couldn't open vms coordinate file\n");
//     exit(-1);
//   }
//   while (1) {
//     /* Generate random relative coordinates */
//     x = random()%20;
//     y = random()%20;
//     if (x%2) x = -x; if (y%2) y = -y;
//     /* Convey simulated coordinates to the virtual mouse driver */
//     sprintf(buffer, "%d %d %d", x, y, 0);
//     write(sim_fd, buffer, strlen(buffer));
//     fsync(sim_fd);
//     sleep(1);
//   }
//   close(sim_fd);
// }
// #include
// #include
// #include
// #include
// #include /home/user/y/ker.aosp/include/linux/platform_device.h
#if 0
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    000042cc            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    000042ee            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_X    000027f0            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    00004332            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    00004365            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_X    000027b3            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    00004388            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_X    00002777            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    000043aa            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_X    0000273a            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    000043ff            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    00004443            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_X    000026df            
/dev/input/event1: EV_ABS       ABS_MT_POSITION_Y    00004465            
/dev/input/event1: EV_SYN       SYN_REPORT           00000000            
/dev/input/event1: EV_ABS       ABS_MT_PRESSURE      00000000            
/dev/input/event1: EV_ABS       ABS_MT_TRACKING_ID   ffffffff  
input_report_key(data->vms_input_dev, data->pdata->keys[i], 1);
input_mt_report_slot_state(data->vms_input_dev, MT_TOOL_FINGER, true);
input_mt_slot(data->vms_input_dev, events[i].id);
input_report_key(data->vms_input_dev, BTN_TOUCH, 0);
#endif
#include <linux/input.h>
#include <linux/platform_device.h>
#include <linux/module.h> 
struct vms_input_dev *vms_input_dev;        /* Representation of an input device */
static struct platform_device *vms_dev; /* Device structure */ /* Sysfs method to input simulated coordinates to the virtual mouse driver */
static ssize_t write_vms(struct device *dev, struct device_attribute *attr, const char *buffer, size_t count) { int x,y;
  sscanf(buffer, "%d%d", &x, &y); /* Report relative coordinates via the event interface */
  input_report_rel(vms_input_dev, REL_X, x);
  input_report_rel(vms_input_dev, REL_Y, y);
  input_sync(vms_input_dev);
  return count; } /* Attach the sysfs write method */
DEVICE_ATTR(coordinates, 0644, NULL, write_vms); /* Attribute Descriptor */
static struct attribute *vms_attrs[] = { &dev_attr_coordinates.attr, NULL }; /* Attribute group */
static struct attribute_group vms_attr_group = { .attrs = vms_attrs, }; /* Driver Initialization */
// static int fts_input_init(struct fts_ts_data *ts_data) { int ret = 0; int key_num = 0; struct fts_ts_platform_data *pdata = ts_data->pdata; struct vms_input_dev *vms_input_dev; FTS_FUNC_ENTER(); vms_input_dev = input_allocate_device(); if (!vms_input_dev) { FTS_ERROR("Failed to allocate memory for input device"); return -ENOMEM; }     /* Init and register Input device */
//     vms_input_dev->name = FTS_DRIVER_NAME; vms_input_dev->id.bustype = BUS_I2C; vms_input_dev->dev.parent = ts_data->dev; input_set_drvdata(vms_input_dev, ts_data); __set_bit(EV_SYN, vms_input_dev->evbit); __set_bit(EV_ABS, vms_input_dev->evbit); __set_bit(EV_KEY, vms_input_dev->evbit);
//     __set_bit(BTN_TOUCH, vms_input_dev->keybit); __set_bit(INPUT_PROP_DIRECT, vms_input_dev->propbit); if (pdata->have_key) { FTS_INFO("set key capabilities"); for (key_num = 0; key_num < pdata->key_number; key_num++) input_set_capability(vms_input_dev, EV_KEY, pdata->keys[key_num]); } //#if FTS_MT_PROTOCOL_B_EN
//     input_mt_init_slots(vms_input_dev, pdata->max_touch_number, INPUT_MT_DIRECT); //#else input_set_abs_params(vms_input_dev, ABS_MT_TRACKING_ID, 0, 0x0F, 0, 0); //#endif
//     input_set_abs_params(vms_input_dev, ABS_MT_POSITION_X, pdata->x_min, pdata->x_max, 0, 0); input_set_abs_params(vms_input_dev, ABS_MT_POSITION_Y, pdata->y_min, pdata->y_max, 0, 0); input_set_abs_params(vms_input_dev, ABS_MT_TOUCH_MAJOR, 0, 0xFF, 0, 0); #if FTS_REPORT_PRESSURE_EN input_set_abs_params(vms_input_dev, ABS_MT_PRESSURE, 0, 0xFF, 0, 0); #endif
//     ret = input_register_device(vms_input_dev); if (ret) { FTS_ERROR("Input device registration failed"); input_set_drvdata(vms_input_dev, NULL); input_free_device(vms_input_dev); vms_input_dev = NULL; return ret; }
//     ts_data->vms_input_dev = vms_input_dev; FTS_FUNC_EXIT(); return 0; }
int __init vms_init(void) { /* Register a platform device */
  vms_dev = platform_device_register_simple("vms", -1, NULL, 0); if (IS_ERR(vms_dev)) { PTR_ERR(vms_dev); printk("vms_init: error\n"); } /* Create a sysfs node to read simulated coordinates */
  sysfs_create_group(&vms_dev->dev.kobj, &vms_attr_group); /* Allocate an input device data structure */
  vms_input_dev = input_allocate_device(); if (!vms_input_dev) { printk("Bad input_alloc_device()\n"); }
  
  __set_bit(EV_SYN, vms_input_dev->evbit); __set_bit(EV_ABS, vms_input_dev->evbit); __set_bit(EV_KEY, vms_input_dev->evbit);  __set_bit(BTN_TOUCH, vms_input_dev->keybit); __set_bit(INPUT_PROP_DIRECT, vms_input_dev->propbit);  
  input_mt_init_slots(vms_input_dev, pdata->max_touch_number, INPUT_MT_DIRECT);
    input_set_abs_params(vms_input_dev, ABS_MT_POSITION_X, 0, 800, 0, 0); input_set_abs_params(vms_input_dev, ABS_MT_POSITION_Y, 0, 800, 0, 0); input_set_abs_params(vms_input_dev, ABS_MT_TOUCH_MAJOR, 0, 0xFF, 0, 0); //#if FTS_REPORT_PRESSURE_EN input_set_abs_params(vms_input_dev, ABS_MT_PRESSURE, 0, 0xFF, 0, 0); #endif

  // set_bit(EV_REL, vms_input_dev->evbit); set_bit(REL_X, vms_input_dev->relbit); set_bit(REL_Y, vms_input_dev->relbit); /* Register with the input subsystem */
  input_register_device(vms_input_dev); printk("Virtual Mouse Driver Initialized.\n"); return 0; } /* Driver Exit */
void vms_cleanup(void) { /* Unregister from the input subsystem */
  input_unregister_device(vms_input_dev); /* Cleanup sysfs node */
  sysfs_remove_group(&vms_dev->dev.kobj, &vms_attr_group); /* Unregister driver */
  platform_device_unregister(vms_dev); return; } module_init(vms_init); module_exit(vms_cleanup);
  MODULE_AUTHOR("FocalTech Driver Team"); MODULE_DESCRIPTION("FocalTech Touchscreen Driver"); MODULE_LICENSE("GPL v2");