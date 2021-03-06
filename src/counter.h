

// Generated by slyft.io
// This code part has been generated on an "as is" basis, without warranties or conditions of any kind.

// slyftlet=c99-generic-msgpack

#ifndef tutci_COUNTER_H
#define tutci_COUNTER_H

#include "mpack/mpack.h"

struct TUTCI__counter {
  /* true->inc and false->dec */
  bool	command;

  /**
  * Wipes contents to \0
  * @param self      pointer to target struct TUTCI__counter
  */
  void (*TUTCI__counter_clean)(struct TUTCI__counter *self);

  /**
  * Given an input buffer and its size, this functions parses the elements
  * of struct TUTCI__counter
  * @param self          pointer to target struct TUTCI__counter
  * @param input_buf     input buffer
  * @param sz_input_buf  size of input buffer
  * @return 0=success, 1=error
  */
  int (*TUTCI__counter_parse)(struct TUTCI__counter *self, const uint8_t *input_buf, size_t sz_input_buf);

  /**
  * Given a msgpack reader, this functions parses the elements
  * of struct TUTCI__counter
  * @param self          pointer to target struct TUTCI__counter
  * @param reader        pointer to mpack reader struct
  */
  void (*TUTCI__counter_parse_mpack)(struct TUTCI__counter *self, mpack_reader_t *reader);

  /**
  * Given a struct TUTCI__counter, this function serializes it into given output buffer.
  * @param self              pointer to source struct TUTCI__counter
  * @param output_buf        output buffer
  * @param sz_output_buf     size of output buffer
  * @return Length of output buf (0=error)
  */
  size_t (*TUTCI__counter_serialize)(const struct TUTCI__counter *self, uint8_t *output_buf, size_t sz_output_buf);

  /**
  * Given a struct TUTCI__counter, this function serializes it into given mpack writer.
  * @param self              pointer to source struct TUTCI__counter
  * @param writer 	         pointer to mpack writer struct
  */
  void (*TUTCI__counter_serialize_mpack)(const struct TUTCI__counter *self, mpack_writer_t *writer);

};

/**
 * Initializes struct struct TUTCI__counter. empties fields, sets function pointers
 * @param self  struct TUTCI__counter
 */
void TUTCI__counter_init(struct TUTCI__counter *self);


/* ORIGINAL SCHEMA
{"$schema"=>"http://json-schema.org/draft-04/schema#", "id"=>"counter", "title"=>"Increase or decrease the counter", "description"=>"Specify inc-dec", "type"=>"object", "properties"=>{"command"=>{"type"=>"boolean", "description"=>"true->inc and false->dec"}}, "additionalProperties"=>false, "required"=>["command"], "minProperties"=>1}
 */
#endif		//tutci_COUNTER_H

