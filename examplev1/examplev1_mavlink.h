//Initialize Timers

unsigned long heartbeatTimer_TX = millis();
unsigned long heartbeatTimer_RX = millis();
unsigned long heartbeatInterval_TX = 1.0L * 1000L;
unsigned long heartbeatInterval_RX = 3L * 1000L;

mavlink_system_t mavlink_system;

uint8_t bufTx[MAVLINK_MAX_PACKET_LEN];
uint8_t bufRx[MAVLINK_MAX_PACKET_LEN];


/**DEFINE ROBOT ID HERE*/
#define BOT_ID 22

//MavLink Fields for Heartbeat
uint8_t system_type = MAV_TYPE_GROUND_ROVER; //MAV_TYPE_HELICOPTER;//MAV_TYPE_FIXED_WING;
uint8_t autopilot_type = MAV_AUTOPILOT_GENERIC; //MAV_AUTOPILOT_ARDUPILOTMEGA
uint8_t system_mode = MAV_MODE_MANUAL_DISARMED; //MAV_MODE_MANUAL_DISARMED; //MAV_MODE_GUIDED_ARMED //MAV_MODE_GUIDED_DISARMED
uint8_t system_state = MAV_STATE_ACTIVE;  //MAV_STATE_STANDBY


// Initialize the required buffers 
mavlink_message_t         receivedMsg; 
mavlink_message_t         heartbeatMsg;
mavlink_message_t         msg;
mavlink_status_t          mav_status;

