// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ColorSettings.proto

#ifndef PROTOBUF_ColorSettings_2eproto__INCLUDED
#define PROTOBUF_ColorSettings_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ColorSettings_2eproto();
void protobuf_AssignDesc_ColorSettings_2eproto();
void protobuf_ShutdownFile_ColorSettings_2eproto();

class ColorSettings;
class ColorSettings_color;

// ===================================================================

class ColorSettings_color : public ::google::protobuf::Message {
 public:
  ColorSettings_color();
  virtual ~ColorSettings_color();
  
  ColorSettings_color(const ColorSettings_color& from);
  
  inline ColorSettings_color& operator=(const ColorSettings_color& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ColorSettings_color& default_instance();
  
  void Swap(ColorSettings_color* other);
  
  // implements Message ----------------------------------------------
  
  ColorSettings_color* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ColorSettings_color& from);
  void MergeFrom(const ColorSettings_color& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required float min_hue = 1;
  inline bool has_min_hue() const;
  inline void clear_min_hue();
  static const int kMinHueFieldNumber = 1;
  inline float min_hue() const;
  inline void set_min_hue(float value);
  
  // required float min_sat = 2;
  inline bool has_min_sat() const;
  inline void clear_min_sat();
  static const int kMinSatFieldNumber = 2;
  inline float min_sat() const;
  inline void set_min_sat(float value);
  
  // required float min_val = 3;
  inline bool has_min_val() const;
  inline void clear_min_val();
  static const int kMinValFieldNumber = 3;
  inline float min_val() const;
  inline void set_min_val(float value);
  
  // required float max_hue = 4;
  inline bool has_max_hue() const;
  inline void clear_max_hue();
  static const int kMaxHueFieldNumber = 4;
  inline float max_hue() const;
  inline void set_max_hue(float value);
  
  // required float max_sat = 5;
  inline bool has_max_sat() const;
  inline void clear_max_sat();
  static const int kMaxSatFieldNumber = 5;
  inline float max_sat() const;
  inline void set_max_sat(float value);
  
  // required float max_val = 6;
  inline bool has_max_val() const;
  inline void clear_max_val();
  static const int kMaxValFieldNumber = 6;
  inline float max_val() const;
  inline void set_max_val(float value);
  
  // @@protoc_insertion_point(class_scope:ColorSettings.color)
 private:
  inline void set_has_min_hue();
  inline void clear_has_min_hue();
  inline void set_has_min_sat();
  inline void clear_has_min_sat();
  inline void set_has_min_val();
  inline void clear_has_min_val();
  inline void set_has_max_hue();
  inline void clear_has_max_hue();
  inline void set_has_max_sat();
  inline void clear_has_max_sat();
  inline void set_has_max_val();
  inline void clear_has_max_val();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  float min_hue_;
  float min_sat_;
  float min_val_;
  float max_hue_;
  float max_sat_;
  float max_val_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];
  
  friend void  protobuf_AddDesc_ColorSettings_2eproto();
  friend void protobuf_AssignDesc_ColorSettings_2eproto();
  friend void protobuf_ShutdownFile_ColorSettings_2eproto();
  
  void InitAsDefaultInstance();
  static ColorSettings_color* default_instance_;
};
// -------------------------------------------------------------------

class ColorSettings : public ::google::protobuf::Message {
 public:
  ColorSettings();
  virtual ~ColorSettings();
  
  ColorSettings(const ColorSettings& from);
  
  inline ColorSettings& operator=(const ColorSettings& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ColorSettings& default_instance();
  
  void Swap(ColorSettings* other);
  
  // implements Message ----------------------------------------------
  
  ColorSettings* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ColorSettings& from);
  void MergeFrom(const ColorSettings& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  typedef ColorSettings_color color;
  
  // accessors -------------------------------------------------------
  
  // required int64 input_WHITE_BALANCE_BLUE_U = 1;
  inline bool has_input_white_balance_blue_u() const;
  inline void clear_input_white_balance_blue_u();
  static const int kInputWHITEBALANCEBLUEUFieldNumber = 1;
  inline ::google::protobuf::int64 input_white_balance_blue_u() const;
  inline void set_input_white_balance_blue_u(::google::protobuf::int64 value);
  
  // required int64 input_WHITE_BALANCE_RED_V = 2;
  inline bool has_input_white_balance_red_v() const;
  inline void clear_input_white_balance_red_v();
  static const int kInputWHITEBALANCEREDVFieldNumber = 2;
  inline ::google::protobuf::int64 input_white_balance_red_v() const;
  inline void set_input_white_balance_red_v(::google::protobuf::int64 value);
  
  // required int64 input_EXPOSURE = 3;
  inline bool has_input_exposure() const;
  inline void clear_input_exposure();
  static const int kInputEXPOSUREFieldNumber = 3;
  inline ::google::protobuf::int64 input_exposure() const;
  inline void set_input_exposure(::google::protobuf::int64 value);
  
  // required int64 input_BRIGHTNESS = 4;
  inline bool has_input_brightness() const;
  inline void clear_input_brightness();
  static const int kInputBRIGHTNESSFieldNumber = 4;
  inline ::google::protobuf::int64 input_brightness() const;
  inline void set_input_brightness(::google::protobuf::int64 value);
  
  // required int32 input_SHARPNESS = 5;
  inline bool has_input_sharpness() const;
  inline void clear_input_sharpness();
  static const int kInputSHARPNESSFieldNumber = 5;
  inline ::google::protobuf::int32 input_sharpness() const;
  inline void set_input_sharpness(::google::protobuf::int32 value);
  
  // required int64 input_GAIN = 6;
  inline bool has_input_gain() const;
  inline void clear_input_gain();
  static const int kInputGAINFieldNumber = 6;
  inline ::google::protobuf::int64 input_gain() const;
  inline void set_input_gain(::google::protobuf::int64 value);
  
  // required int64 input_HUE = 7;
  inline bool has_input_hue() const;
  inline void clear_input_hue();
  static const int kInputHUEFieldNumber = 7;
  inline ::google::protobuf::int64 input_hue() const;
  inline void set_input_hue(::google::protobuf::int64 value);
  
  // required int64 input_SAT = 8;
  inline bool has_input_sat() const;
  inline void clear_input_sat();
  static const int kInputSATFieldNumber = 8;
  inline ::google::protobuf::int64 input_sat() const;
  inline void set_input_sat(::google::protobuf::int64 value);
  
  // required int64 input_CONTRAST = 9;
  inline bool has_input_contrast() const;
  inline void clear_input_contrast();
  static const int kInputCONTRASTFieldNumber = 9;
  inline ::google::protobuf::int64 input_contrast() const;
  inline void set_input_contrast(::google::protobuf::int64 value);
  
  // repeated .ColorSettings.color red_instances = 10;
  inline int red_instances_size() const;
  inline void clear_red_instances();
  static const int kRedInstancesFieldNumber = 10;
  inline const ::ColorSettings_color& red_instances(int index) const;
  inline ::ColorSettings_color* mutable_red_instances(int index);
  inline ::ColorSettings_color* add_red_instances();
  inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
      red_instances() const;
  inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
      mutable_red_instances();
  
  // repeated .ColorSettings.color blue_instances = 11;
  inline int blue_instances_size() const;
  inline void clear_blue_instances();
  static const int kBlueInstancesFieldNumber = 11;
  inline const ::ColorSettings_color& blue_instances(int index) const;
  inline ::ColorSettings_color* mutable_blue_instances(int index);
  inline ::ColorSettings_color* add_blue_instances();
  inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
      blue_instances() const;
  inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
      mutable_blue_instances();
  
  // repeated .ColorSettings.color green_instances = 12;
  inline int green_instances_size() const;
  inline void clear_green_instances();
  static const int kGreenInstancesFieldNumber = 12;
  inline const ::ColorSettings_color& green_instances(int index) const;
  inline ::ColorSettings_color* mutable_green_instances(int index);
  inline ::ColorSettings_color* add_green_instances();
  inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
      green_instances() const;
  inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
      mutable_green_instances();
  
  // repeated .ColorSettings.color yellow_instances = 13;
  inline int yellow_instances_size() const;
  inline void clear_yellow_instances();
  static const int kYellowInstancesFieldNumber = 13;
  inline const ::ColorSettings_color& yellow_instances(int index) const;
  inline ::ColorSettings_color* mutable_yellow_instances(int index);
  inline ::ColorSettings_color* add_yellow_instances();
  inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
      yellow_instances() const;
  inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
      mutable_yellow_instances();
  
  // repeated .ColorSettings.color violet_instances = 14;
  inline int violet_instances_size() const;
  inline void clear_violet_instances();
  static const int kVioletInstancesFieldNumber = 14;
  inline const ::ColorSettings_color& violet_instances(int index) const;
  inline ::ColorSettings_color* mutable_violet_instances(int index);
  inline ::ColorSettings_color* add_violet_instances();
  inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
      violet_instances() const;
  inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
      mutable_violet_instances();
  
  // repeated .ColorSettings.color cyan_instances = 15;
  inline int cyan_instances_size() const;
  inline void clear_cyan_instances();
  static const int kCyanInstancesFieldNumber = 15;
  inline const ::ColorSettings_color& cyan_instances(int index) const;
  inline ::ColorSettings_color* mutable_cyan_instances(int index);
  inline ::ColorSettings_color* add_cyan_instances();
  inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
      cyan_instances() const;
  inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
      mutable_cyan_instances();
  
  // repeated .ColorSettings.color black_instances = 16;
  inline int black_instances_size() const;
  inline void clear_black_instances();
  static const int kBlackInstancesFieldNumber = 16;
  inline const ::ColorSettings_color& black_instances(int index) const;
  inline ::ColorSettings_color* mutable_black_instances(int index);
  inline ::ColorSettings_color* add_black_instances();
  inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
      black_instances() const;
  inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
      mutable_black_instances();
  
  // @@protoc_insertion_point(class_scope:ColorSettings)
 private:
  inline void set_has_input_white_balance_blue_u();
  inline void clear_has_input_white_balance_blue_u();
  inline void set_has_input_white_balance_red_v();
  inline void clear_has_input_white_balance_red_v();
  inline void set_has_input_exposure();
  inline void clear_has_input_exposure();
  inline void set_has_input_brightness();
  inline void clear_has_input_brightness();
  inline void set_has_input_sharpness();
  inline void clear_has_input_sharpness();
  inline void set_has_input_gain();
  inline void clear_has_input_gain();
  inline void set_has_input_hue();
  inline void clear_has_input_hue();
  inline void set_has_input_sat();
  inline void clear_has_input_sat();
  inline void set_has_input_contrast();
  inline void clear_has_input_contrast();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int64 input_white_balance_blue_u_;
  ::google::protobuf::int64 input_white_balance_red_v_;
  ::google::protobuf::int64 input_exposure_;
  ::google::protobuf::int64 input_brightness_;
  ::google::protobuf::int64 input_gain_;
  ::google::protobuf::int64 input_hue_;
  ::google::protobuf::int64 input_sat_;
  ::google::protobuf::int64 input_contrast_;
  ::google::protobuf::RepeatedPtrField< ::ColorSettings_color > red_instances_;
  ::google::protobuf::RepeatedPtrField< ::ColorSettings_color > blue_instances_;
  ::google::protobuf::RepeatedPtrField< ::ColorSettings_color > green_instances_;
  ::google::protobuf::RepeatedPtrField< ::ColorSettings_color > yellow_instances_;
  ::google::protobuf::RepeatedPtrField< ::ColorSettings_color > violet_instances_;
  ::google::protobuf::RepeatedPtrField< ::ColorSettings_color > cyan_instances_;
  ::google::protobuf::RepeatedPtrField< ::ColorSettings_color > black_instances_;
  ::google::protobuf::int32 input_sharpness_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(16 + 31) / 32];
  
  friend void  protobuf_AddDesc_ColorSettings_2eproto();
  friend void protobuf_AssignDesc_ColorSettings_2eproto();
  friend void protobuf_ShutdownFile_ColorSettings_2eproto();
  
  void InitAsDefaultInstance();
  static ColorSettings* default_instance_;
};
// ===================================================================


// ===================================================================

// ColorSettings_color

// required float min_hue = 1;
inline bool ColorSettings_color::has_min_hue() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ColorSettings_color::set_has_min_hue() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ColorSettings_color::clear_has_min_hue() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ColorSettings_color::clear_min_hue() {
  min_hue_ = 0;
  clear_has_min_hue();
}
inline float ColorSettings_color::min_hue() const {
  return min_hue_;
}
inline void ColorSettings_color::set_min_hue(float value) {
  set_has_min_hue();
  min_hue_ = value;
}

// required float min_sat = 2;
inline bool ColorSettings_color::has_min_sat() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ColorSettings_color::set_has_min_sat() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ColorSettings_color::clear_has_min_sat() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ColorSettings_color::clear_min_sat() {
  min_sat_ = 0;
  clear_has_min_sat();
}
inline float ColorSettings_color::min_sat() const {
  return min_sat_;
}
inline void ColorSettings_color::set_min_sat(float value) {
  set_has_min_sat();
  min_sat_ = value;
}

// required float min_val = 3;
inline bool ColorSettings_color::has_min_val() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ColorSettings_color::set_has_min_val() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ColorSettings_color::clear_has_min_val() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ColorSettings_color::clear_min_val() {
  min_val_ = 0;
  clear_has_min_val();
}
inline float ColorSettings_color::min_val() const {
  return min_val_;
}
inline void ColorSettings_color::set_min_val(float value) {
  set_has_min_val();
  min_val_ = value;
}

// required float max_hue = 4;
inline bool ColorSettings_color::has_max_hue() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ColorSettings_color::set_has_max_hue() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ColorSettings_color::clear_has_max_hue() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ColorSettings_color::clear_max_hue() {
  max_hue_ = 0;
  clear_has_max_hue();
}
inline float ColorSettings_color::max_hue() const {
  return max_hue_;
}
inline void ColorSettings_color::set_max_hue(float value) {
  set_has_max_hue();
  max_hue_ = value;
}

// required float max_sat = 5;
inline bool ColorSettings_color::has_max_sat() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ColorSettings_color::set_has_max_sat() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ColorSettings_color::clear_has_max_sat() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ColorSettings_color::clear_max_sat() {
  max_sat_ = 0;
  clear_has_max_sat();
}
inline float ColorSettings_color::max_sat() const {
  return max_sat_;
}
inline void ColorSettings_color::set_max_sat(float value) {
  set_has_max_sat();
  max_sat_ = value;
}

// required float max_val = 6;
inline bool ColorSettings_color::has_max_val() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ColorSettings_color::set_has_max_val() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ColorSettings_color::clear_has_max_val() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ColorSettings_color::clear_max_val() {
  max_val_ = 0;
  clear_has_max_val();
}
inline float ColorSettings_color::max_val() const {
  return max_val_;
}
inline void ColorSettings_color::set_max_val(float value) {
  set_has_max_val();
  max_val_ = value;
}

// -------------------------------------------------------------------

// ColorSettings

// required int64 input_WHITE_BALANCE_BLUE_U = 1;
inline bool ColorSettings::has_input_white_balance_blue_u() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ColorSettings::set_has_input_white_balance_blue_u() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ColorSettings::clear_has_input_white_balance_blue_u() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ColorSettings::clear_input_white_balance_blue_u() {
  input_white_balance_blue_u_ = GOOGLE_LONGLONG(0);
  clear_has_input_white_balance_blue_u();
}
inline ::google::protobuf::int64 ColorSettings::input_white_balance_blue_u() const {
  return input_white_balance_blue_u_;
}
inline void ColorSettings::set_input_white_balance_blue_u(::google::protobuf::int64 value) {
  set_has_input_white_balance_blue_u();
  input_white_balance_blue_u_ = value;
}

// required int64 input_WHITE_BALANCE_RED_V = 2;
inline bool ColorSettings::has_input_white_balance_red_v() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ColorSettings::set_has_input_white_balance_red_v() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ColorSettings::clear_has_input_white_balance_red_v() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ColorSettings::clear_input_white_balance_red_v() {
  input_white_balance_red_v_ = GOOGLE_LONGLONG(0);
  clear_has_input_white_balance_red_v();
}
inline ::google::protobuf::int64 ColorSettings::input_white_balance_red_v() const {
  return input_white_balance_red_v_;
}
inline void ColorSettings::set_input_white_balance_red_v(::google::protobuf::int64 value) {
  set_has_input_white_balance_red_v();
  input_white_balance_red_v_ = value;
}

// required int64 input_EXPOSURE = 3;
inline bool ColorSettings::has_input_exposure() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ColorSettings::set_has_input_exposure() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ColorSettings::clear_has_input_exposure() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ColorSettings::clear_input_exposure() {
  input_exposure_ = GOOGLE_LONGLONG(0);
  clear_has_input_exposure();
}
inline ::google::protobuf::int64 ColorSettings::input_exposure() const {
  return input_exposure_;
}
inline void ColorSettings::set_input_exposure(::google::protobuf::int64 value) {
  set_has_input_exposure();
  input_exposure_ = value;
}

// required int64 input_BRIGHTNESS = 4;
inline bool ColorSettings::has_input_brightness() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ColorSettings::set_has_input_brightness() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ColorSettings::clear_has_input_brightness() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ColorSettings::clear_input_brightness() {
  input_brightness_ = GOOGLE_LONGLONG(0);
  clear_has_input_brightness();
}
inline ::google::protobuf::int64 ColorSettings::input_brightness() const {
  return input_brightness_;
}
inline void ColorSettings::set_input_brightness(::google::protobuf::int64 value) {
  set_has_input_brightness();
  input_brightness_ = value;
}

// required int32 input_SHARPNESS = 5;
inline bool ColorSettings::has_input_sharpness() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ColorSettings::set_has_input_sharpness() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ColorSettings::clear_has_input_sharpness() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ColorSettings::clear_input_sharpness() {
  input_sharpness_ = 0;
  clear_has_input_sharpness();
}
inline ::google::protobuf::int32 ColorSettings::input_sharpness() const {
  return input_sharpness_;
}
inline void ColorSettings::set_input_sharpness(::google::protobuf::int32 value) {
  set_has_input_sharpness();
  input_sharpness_ = value;
}

// required int64 input_GAIN = 6;
inline bool ColorSettings::has_input_gain() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ColorSettings::set_has_input_gain() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ColorSettings::clear_has_input_gain() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ColorSettings::clear_input_gain() {
  input_gain_ = GOOGLE_LONGLONG(0);
  clear_has_input_gain();
}
inline ::google::protobuf::int64 ColorSettings::input_gain() const {
  return input_gain_;
}
inline void ColorSettings::set_input_gain(::google::protobuf::int64 value) {
  set_has_input_gain();
  input_gain_ = value;
}

// required int64 input_HUE = 7;
inline bool ColorSettings::has_input_hue() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ColorSettings::set_has_input_hue() {
  _has_bits_[0] |= 0x00000040u;
}
inline void ColorSettings::clear_has_input_hue() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void ColorSettings::clear_input_hue() {
  input_hue_ = GOOGLE_LONGLONG(0);
  clear_has_input_hue();
}
inline ::google::protobuf::int64 ColorSettings::input_hue() const {
  return input_hue_;
}
inline void ColorSettings::set_input_hue(::google::protobuf::int64 value) {
  set_has_input_hue();
  input_hue_ = value;
}

// required int64 input_SAT = 8;
inline bool ColorSettings::has_input_sat() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void ColorSettings::set_has_input_sat() {
  _has_bits_[0] |= 0x00000080u;
}
inline void ColorSettings::clear_has_input_sat() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void ColorSettings::clear_input_sat() {
  input_sat_ = GOOGLE_LONGLONG(0);
  clear_has_input_sat();
}
inline ::google::protobuf::int64 ColorSettings::input_sat() const {
  return input_sat_;
}
inline void ColorSettings::set_input_sat(::google::protobuf::int64 value) {
  set_has_input_sat();
  input_sat_ = value;
}

// required int64 input_CONTRAST = 9;
inline bool ColorSettings::has_input_contrast() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void ColorSettings::set_has_input_contrast() {
  _has_bits_[0] |= 0x00000100u;
}
inline void ColorSettings::clear_has_input_contrast() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void ColorSettings::clear_input_contrast() {
  input_contrast_ = GOOGLE_LONGLONG(0);
  clear_has_input_contrast();
}
inline ::google::protobuf::int64 ColorSettings::input_contrast() const {
  return input_contrast_;
}
inline void ColorSettings::set_input_contrast(::google::protobuf::int64 value) {
  set_has_input_contrast();
  input_contrast_ = value;
}

// repeated .ColorSettings.color red_instances = 10;
inline int ColorSettings::red_instances_size() const {
  return red_instances_.size();
}
inline void ColorSettings::clear_red_instances() {
  red_instances_.Clear();
}
inline const ::ColorSettings_color& ColorSettings::red_instances(int index) const {
  return red_instances_.Get(index);
}
inline ::ColorSettings_color* ColorSettings::mutable_red_instances(int index) {
  return red_instances_.Mutable(index);
}
inline ::ColorSettings_color* ColorSettings::add_red_instances() {
  return red_instances_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
ColorSettings::red_instances() const {
  return red_instances_;
}
inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
ColorSettings::mutable_red_instances() {
  return &red_instances_;
}

// repeated .ColorSettings.color blue_instances = 11;
inline int ColorSettings::blue_instances_size() const {
  return blue_instances_.size();
}
inline void ColorSettings::clear_blue_instances() {
  blue_instances_.Clear();
}
inline const ::ColorSettings_color& ColorSettings::blue_instances(int index) const {
  return blue_instances_.Get(index);
}
inline ::ColorSettings_color* ColorSettings::mutable_blue_instances(int index) {
  return blue_instances_.Mutable(index);
}
inline ::ColorSettings_color* ColorSettings::add_blue_instances() {
  return blue_instances_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
ColorSettings::blue_instances() const {
  return blue_instances_;
}
inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
ColorSettings::mutable_blue_instances() {
  return &blue_instances_;
}

// repeated .ColorSettings.color green_instances = 12;
inline int ColorSettings::green_instances_size() const {
  return green_instances_.size();
}
inline void ColorSettings::clear_green_instances() {
  green_instances_.Clear();
}
inline const ::ColorSettings_color& ColorSettings::green_instances(int index) const {
  return green_instances_.Get(index);
}
inline ::ColorSettings_color* ColorSettings::mutable_green_instances(int index) {
  return green_instances_.Mutable(index);
}
inline ::ColorSettings_color* ColorSettings::add_green_instances() {
  return green_instances_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
ColorSettings::green_instances() const {
  return green_instances_;
}
inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
ColorSettings::mutable_green_instances() {
  return &green_instances_;
}

// repeated .ColorSettings.color yellow_instances = 13;
inline int ColorSettings::yellow_instances_size() const {
  return yellow_instances_.size();
}
inline void ColorSettings::clear_yellow_instances() {
  yellow_instances_.Clear();
}
inline const ::ColorSettings_color& ColorSettings::yellow_instances(int index) const {
  return yellow_instances_.Get(index);
}
inline ::ColorSettings_color* ColorSettings::mutable_yellow_instances(int index) {
  return yellow_instances_.Mutable(index);
}
inline ::ColorSettings_color* ColorSettings::add_yellow_instances() {
  return yellow_instances_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
ColorSettings::yellow_instances() const {
  return yellow_instances_;
}
inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
ColorSettings::mutable_yellow_instances() {
  return &yellow_instances_;
}

// repeated .ColorSettings.color violet_instances = 14;
inline int ColorSettings::violet_instances_size() const {
  return violet_instances_.size();
}
inline void ColorSettings::clear_violet_instances() {
  violet_instances_.Clear();
}
inline const ::ColorSettings_color& ColorSettings::violet_instances(int index) const {
  return violet_instances_.Get(index);
}
inline ::ColorSettings_color* ColorSettings::mutable_violet_instances(int index) {
  return violet_instances_.Mutable(index);
}
inline ::ColorSettings_color* ColorSettings::add_violet_instances() {
  return violet_instances_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
ColorSettings::violet_instances() const {
  return violet_instances_;
}
inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
ColorSettings::mutable_violet_instances() {
  return &violet_instances_;
}

// repeated .ColorSettings.color cyan_instances = 15;
inline int ColorSettings::cyan_instances_size() const {
  return cyan_instances_.size();
}
inline void ColorSettings::clear_cyan_instances() {
  cyan_instances_.Clear();
}
inline const ::ColorSettings_color& ColorSettings::cyan_instances(int index) const {
  return cyan_instances_.Get(index);
}
inline ::ColorSettings_color* ColorSettings::mutable_cyan_instances(int index) {
  return cyan_instances_.Mutable(index);
}
inline ::ColorSettings_color* ColorSettings::add_cyan_instances() {
  return cyan_instances_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
ColorSettings::cyan_instances() const {
  return cyan_instances_;
}
inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
ColorSettings::mutable_cyan_instances() {
  return &cyan_instances_;
}

// repeated .ColorSettings.color black_instances = 16;
inline int ColorSettings::black_instances_size() const {
  return black_instances_.size();
}
inline void ColorSettings::clear_black_instances() {
  black_instances_.Clear();
}
inline const ::ColorSettings_color& ColorSettings::black_instances(int index) const {
  return black_instances_.Get(index);
}
inline ::ColorSettings_color* ColorSettings::mutable_black_instances(int index) {
  return black_instances_.Mutable(index);
}
inline ::ColorSettings_color* ColorSettings::add_black_instances() {
  return black_instances_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >&
ColorSettings::black_instances() const {
  return black_instances_;
}
inline ::google::protobuf::RepeatedPtrField< ::ColorSettings_color >*
ColorSettings::mutable_black_instances() {
  return &black_instances_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ColorSettings_2eproto__INCLUDED
