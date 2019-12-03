#pragma once
// MESSAGE LIFTING_SURFACE_ANGLES PACKING

#define MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES 187

MAVPACKED(
typedef struct __mavlink_lifting_surface_angles_t {
 float wing_angle; /*<  right wing angle in degrees from horizontal facing forward*/
}) mavlink_lifting_surface_angles_t;

#define MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN 4
#define MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN 4
#define MAVLINK_MSG_ID_187_LEN 4
#define MAVLINK_MSG_ID_187_MIN_LEN 4

#define MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC 46
#define MAVLINK_MSG_ID_187_CRC 46



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LIFTING_SURFACE_ANGLES { \
    187, \
    "LIFTING_SURFACE_ANGLES", \
    1, \
    {  { "wing_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lifting_surface_angles_t, wing_angle) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LIFTING_SURFACE_ANGLES { \
    "LIFTING_SURFACE_ANGLES", \
    1, \
    {  { "wing_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lifting_surface_angles_t, wing_angle) }, \
         } \
}
#endif

/**
 * @brief Pack a lifting_surface_angles message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param wing_angle  right wing angle in degrees from horizontal facing forward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lifting_surface_angles_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float wing_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN];
    _mav_put_float(buf, 0, wing_angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN);
#else
    mavlink_lifting_surface_angles_t packet;
    packet.wing_angle = wing_angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC);
}

/**
 * @brief Pack a lifting_surface_angles message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wing_angle  right wing angle in degrees from horizontal facing forward
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lifting_surface_angles_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float wing_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN];
    _mav_put_float(buf, 0, wing_angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN);
#else
    mavlink_lifting_surface_angles_t packet;
    packet.wing_angle = wing_angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC);
}

/**
 * @brief Encode a lifting_surface_angles struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lifting_surface_angles C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lifting_surface_angles_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lifting_surface_angles_t* lifting_surface_angles)
{
    return mavlink_msg_lifting_surface_angles_pack(system_id, component_id, msg, lifting_surface_angles->wing_angle);
}

/**
 * @brief Encode a lifting_surface_angles struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lifting_surface_angles C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lifting_surface_angles_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lifting_surface_angles_t* lifting_surface_angles)
{
    return mavlink_msg_lifting_surface_angles_pack_chan(system_id, component_id, chan, msg, lifting_surface_angles->wing_angle);
}

/**
 * @brief Send a lifting_surface_angles message
 * @param chan MAVLink channel to send the message
 *
 * @param wing_angle  right wing angle in degrees from horizontal facing forward
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lifting_surface_angles_send(mavlink_channel_t chan, float wing_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN];
    _mav_put_float(buf, 0, wing_angle);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES, buf, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC);
#else
    mavlink_lifting_surface_angles_t packet;
    packet.wing_angle = wing_angle;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES, (const char *)&packet, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC);
#endif
}

/**
 * @brief Send a lifting_surface_angles message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lifting_surface_angles_send_struct(mavlink_channel_t chan, const mavlink_lifting_surface_angles_t* lifting_surface_angles)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lifting_surface_angles_send(chan, lifting_surface_angles->wing_angle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES, (const char *)lifting_surface_angles, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC);
#endif
}

#if MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lifting_surface_angles_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float wing_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, wing_angle);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES, buf, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC);
#else
    mavlink_lifting_surface_angles_t *packet = (mavlink_lifting_surface_angles_t *)msgbuf;
    packet->wing_angle = wing_angle;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES, (const char *)packet, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_MIN_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_CRC);
#endif
}
#endif

#endif

// MESSAGE LIFTING_SURFACE_ANGLES UNPACKING


/**
 * @brief Get field wing_angle from lifting_surface_angles message
 *
 * @return  right wing angle in degrees from horizontal facing forward
 */
static inline float mavlink_msg_lifting_surface_angles_get_wing_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a lifting_surface_angles message into a struct
 *
 * @param msg The message to decode
 * @param lifting_surface_angles C-struct to decode the message contents into
 */
static inline void mavlink_msg_lifting_surface_angles_decode(const mavlink_message_t* msg, mavlink_lifting_surface_angles_t* lifting_surface_angles)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lifting_surface_angles->wing_angle = mavlink_msg_lifting_surface_angles_get_wing_angle(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN? msg->len : MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN;
        memset(lifting_surface_angles, 0, MAVLINK_MSG_ID_LIFTING_SURFACE_ANGLES_LEN);
    memcpy(lifting_surface_angles, _MAV_PAYLOAD(msg), len);
#endif
}
