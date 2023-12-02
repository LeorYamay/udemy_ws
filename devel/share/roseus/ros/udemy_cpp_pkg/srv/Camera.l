;; Auto-generated. Do not edit!


(when (boundp 'udemy_cpp_pkg::Camera)
  (if (not (find-package "UDEMY_CPP_PKG"))
    (make-package "UDEMY_CPP_PKG"))
  (shadow 'Camera (find-package "UDEMY_CPP_PKG")))
(unless (find-package "UDEMY_CPP_PKG::CAMERA")
  (make-package "UDEMY_CPP_PKG::CAMERA"))
(unless (find-package "UDEMY_CPP_PKG::CAMERAREQUEST")
  (make-package "UDEMY_CPP_PKG::CAMERAREQUEST"))
(unless (find-package "UDEMY_CPP_PKG::CAMERARESPONSE")
  (make-package "UDEMY_CPP_PKG::CAMERARESPONSE"))

(in-package "ROS")



(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(defclass udemy_cpp_pkg::CameraRequest
  :super ros::object
  :slots (_angle ))

(defmethod udemy_cpp_pkg::CameraRequest
  (:init
   (&key
    ((:angle __angle) 0)
    )
   (send-super :init)
   (setq _angle (round __angle))
   self)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; int32 _angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _angle
       (write-long _angle s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _angle
     (setq _angle (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass udemy_cpp_pkg::CameraResponse
  :super ros::object
  :slots (_camera_image ))

(defmethod udemy_cpp_pkg::CameraResponse
  (:init
   (&key
    ((:camera_image __camera_image) (instance sensor_msgs::Image :init))
    )
   (send-super :init)
   (setq _camera_image __camera_image)
   self)
  (:camera_image
   (&rest __camera_image)
   (if (keywordp (car __camera_image))
       (send* _camera_image __camera_image)
     (progn
       (if __camera_image (setq _camera_image (car __camera_image)))
       _camera_image)))
  (:serialization-length
   ()
   (+
    ;; sensor_msgs/Image _camera_image
    (send _camera_image :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sensor_msgs/Image _camera_image
       (send _camera_image :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sensor_msgs/Image _camera_image
     (send _camera_image :deserialize buf ptr-) (incf ptr- (send _camera_image :serialization-length))
   ;;
   self)
  )

(defclass udemy_cpp_pkg::Camera
  :super ros::object
  :slots ())

(setf (get udemy_cpp_pkg::Camera :md5sum-) "4d104955aea5eb62c3dd701126361acc")
(setf (get udemy_cpp_pkg::Camera :datatype-) "udemy_cpp_pkg/Camera")
(setf (get udemy_cpp_pkg::Camera :request) udemy_cpp_pkg::CameraRequest)
(setf (get udemy_cpp_pkg::Camera :response) udemy_cpp_pkg::CameraResponse)

(defmethod udemy_cpp_pkg::CameraRequest
  (:response () (instance udemy_cpp_pkg::CameraResponse :init)))

(setf (get udemy_cpp_pkg::CameraRequest :md5sum-) "4d104955aea5eb62c3dd701126361acc")
(setf (get udemy_cpp_pkg::CameraRequest :datatype-) "udemy_cpp_pkg/CameraRequest")
(setf (get udemy_cpp_pkg::CameraRequest :definition-)
      "int32 angle
---
sensor_msgs/Image camera_image

================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id
")

(setf (get udemy_cpp_pkg::CameraResponse :md5sum-) "4d104955aea5eb62c3dd701126361acc")
(setf (get udemy_cpp_pkg::CameraResponse :datatype-) "udemy_cpp_pkg/CameraResponse")
(setf (get udemy_cpp_pkg::CameraResponse :definition-)
      "int32 angle
---
sensor_msgs/Image camera_image

================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id
")



(provide :udemy_cpp_pkg/Camera "4d104955aea5eb62c3dd701126361acc")


