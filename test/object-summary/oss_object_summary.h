/*
 * =============================================================================
 *
 *       Filename:  oss_object_summary.h
 *
 *    Description:  oss_object_summary.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_SUMMARY_H
# error Never include <ossc/oss_object_summary.h> directly, use <ossc/client.h> instead.
#endif

#define _OSS_OWNER_H
#include  "oss_owner.h"
#undef _OSS_OWNER_H

#ifndef OSS_OBJECT_SUMMARY_H
#define OSS_OBJECT_SUMMARY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define HAVE_STDBOOL_H

#ifdef HAVE_STDBOOL_H
#include <stdbool.h>
#endif

typedef struct oss_object_summary_s oss_object_summary_t;

struct oss_object_summary_s {
	char *bucket_name;
	char *etag;
	char *key;
	char *last_modified;
	oss_owner_t *owner;
	long size;
	char *storage_class;

	const char * (*get_bucket_name)(oss_object_summary_t *os);
	void (*set_bucket_name)(oss_object_summary_t *os, const char *bucket_name);

	const char * (*get_etag)(oss_object_summary_t *os);
	void (*set_etag)(oss_object_summary_t *os, const char * etag);

	const char * (*get_key)(oss_object_summary_t *os);
	void (*set_key)(oss_object_summary_t *os, const char *key);

	const char * (*get_last_modified)(oss_object_summary_t *os);
	void (*set_last_modified)(oss_object_summary_t *os, const char *last_modified);

	oss_owner_t * (*get_owner)(oss_object_summary_t *os);
	void (*set_owner)(oss_object_summary_t *os, oss_owner_t *owner);
	
	long  (*get_size)(oss_object_summary_t *os);
	void (*set_size)(oss_object_summary_t *os, long size);

	const char * (*get_storage_class)(oss_object_summary_t *os);
	void (*set_storage_class)(oss_object_summary_t *os, const char *storage_class);
};

extern oss_object_summary_t *
object_summary_initialize(void);

extern void 
object_summary_finalize(oss_object_summary_t *os);

#endif
