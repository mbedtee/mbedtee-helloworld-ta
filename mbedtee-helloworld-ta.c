// SPDX-License-Identifier: Apache-2.0
/*
 * Copyright (c) 2019 KapaXL (kapa.xl@outlook.com)
 * MbedTEE HelloWorld TA
 */

#include <mmap.h>
#include <unistd.h>
#include <fcntl.h>

#include <tee_internal_api.h>

TEE_Result TA_EXPORT TA_CreateEntryPoint(void)
{
	printf("HelloWorld - %s\n", __func__);
	return TEE_SUCCESS;
}

void TA_EXPORT TA_DestroyEntryPoint(void)
{
	printf("HelloWorld - %s\n", __func__);
}

TEE_Result TA_EXPORT TA_OpenSessionEntryPoint(
		uint32_t paramTypes,
		TEE_Param params[4],
		void **session)
{
	printf("HelloWorld - %s\n", __func__);

	return TEE_SUCCESS;
}

void TA_EXPORT TA_CloseSessionEntryPoint(void *session)
{
	printf("HelloWorld - %s\n", __func__);
}

TEE_Result TA_EXPORT TA_InvokeCommandEntryPoint(
		void *session, uint32_t cmd_id,
		uint32_t paramtypes, TEE_Param params[4])
{
	printf("HelloWorld - TA_InvokeCommandEntryPoint cmd %d types %d\n",
			(int)cmd_id, (int)paramtypes);

	return TEE_SUCCESS;
}
