/********************************************************
 * Sketch to demonstrate Mavlink V2.0 communication
 *
 * Serial1 UART is used for mavlink
 *********************************************************/            

#include "mavlink2.h"           // generic library
#include "examplev2_mavlink.h"  // sketch-specific usage of library
#include "printf.h"

#define console Serial
#define telem   Serial1

void setup()
{  
    console.begin(115200);
    telem.begin(115200);
}


void loop()
{
    if ((millis() - heartbeatTimer_RX) > heartbeatInterval_RX) {
        printf ( "Missing RX heartbeat\n\r" );
        heartbeatTimer_RX = millis();
    }

    //Pack and send heartbeat at specific interval to the GCS
    if((millis() - heartbeatTimer_TX) > heartbeatInterval_TX) {
        heartbeatTimer_TX = millis();
        send_heartbeat();
    }

    examplev2_receive();
}

void examplev2_receive()
{
    bool activity = false;

    while (telem.available() > 0) {
        activity = true;
        uint8_t c = telem.read();
        if (mavlink_parse_char(MAVLINK_COMM_0, c, &receivedMsg, &mav_status)) {

            switch(receivedMsg.msgid) {        
            case MAVLINK_MSG_ID_HEARTBEAT:
                heartbeatTimer_RX = millis(); //Reset receive timer 
                printf("RX Heartbeat\n\r" );
                break;

            default:
                /* What you do with other messages depends on your app */
                break;
            }
        }
    }

    if (!activity) {
        /* Give main loop some idle time */
        delayMicroseconds(200);
    }
}


/*
 * I would like to improve this, have to figure out which mavlink helper functions
 * work best in this environment
 */
void send_heartbeat()
{
    memset(bufTx, 0xFF, sizeof(bufTx));
    mavlink_system.sysid = MAV_TYPE_GROUND_ROVER;
    mavlink_system.compid = MAV_COMP_ID_AUTOPILOT1; 
    
    // Pack the message into the heartbeatMsg for sending
    mavlink_msg_heartbeat_pack(mavlink_system.sysid, mavlink_system.compid, &heartbeatMsg,
                               MAV_TYPE_GENERIC, MAV_AUTOPILOT_ARDUPILOTMEGA,
                               MAV_MODE_PREFLIGHT, MAV_MODE_FLAG_CUSTOM_MODE_ENABLED,
                               MAV_STATE_ACTIVE );

    // Copy the message to send buffer 
    uint16_t len = mavlink_msg_to_send_buffer(bufTx, &heartbeatMsg);

    // Write Message    
    telem.write(bufTx, len);        
    heartbeatTimer_TX = millis();
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
    printf("TX Heartbeat %d", status->current_tx_seq); 
}
