/*
 * =============================================================================
 *
 *       Filename:  oss_access_control_list.h
 *
 *    Description:  oss_access_control_list.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_ACCESS_CONTROL_LIST_H
# error Never include <ossc/modules/oss_access_control_list.h> directly, use <ossc/client.h> instead.
#endif

#ifndef OSS_ACCESS_CONTROL_LIST_H
#define OSS_ACCESS_CONTROL_LIST_H
#include "ossc-config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_OWNER_H
#include "ossc/modules/oss_owner.h"
#undef _OSS_OWNER_H

#define _OSS_GRANT_H
#include "ossc/modules/oss_grant.h"
#undef _OSS_GRANT_H

typedef struct oss_access_control_list_s oss_access_control_list_t;

struct oss_access_control_list_s {
	oss_owner_t *owner;
	//oss_grant_t *grants;
	//int grant_number_count;
	char *grant;


	oss_owner_t * (*get_owner)(oss_access_control_list_t *acl);
	void (*set_owner)(oss_access_control_list_t *acl, oss_owner_t * owner);

	const char * (*get_grant)(oss_access_control_list_t *acl);
	void (*set_grant)(oss_access_control_list_t *acl, const char *grant);

	//void (*grant_permission)(oss_access_control_list_t *acl, const char *identifier, const char *permission);
	//void (*revoke_all_permissions)(oss_access_control_list_t* acl, const char *identifier);
	//oss_grant_t * (*get_grants)(oss_access_control_list_t *acl);

};

extern oss_access_control_list_t *
access_control_list_initialize(void);

extern void 
access_control_list_finalize(oss_access_control_list_t *access_control_list);

#endif
