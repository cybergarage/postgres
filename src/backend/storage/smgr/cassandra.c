/*-------------------------------------------------------------------------
 *
 * cassandra.c
 *   This code manages relations that reside on magnetic disk.
 *
 * Or at least, that was what the Berkeley folk had in mind when they named
 * this file.  In reality, what this code provides is an interface from
 * the smgr API to Unix-like filesystem APIs, so it will work with any type
 * of device for which the operating system provides filesystem support.
 * It doesn't matter whether the bits are on spinning rust or some other
 * storage technology.
 *
 * Portions Copyright (c) 1996-2016, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *   src/backend/storage/smgr/cassandra.c
 *
 *-------------------------------------------------------------------------
 */
#include "postgres.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

#include "miscadmin.h"
#include "access/xlog.h"
#include "catalog/catalog.h"
#include "portability/instr_time.h"
#include "postmaster/bgwriter.h"
#include "storage/fd.h"
#include "storage/bufmgr.h"
#include "storage/relfilenode.h"
#include "storage/smgr.h"
#include "utils/hsearch.h"
#include "utils/memutils.h"
#include "pg_trace.h"

/*
 *	cassandra_init() -- Initialize private state for magnetic disk storage manager.
 */
void
cassandra_init(void)
{
}

/*
 *	cassandra_shutdown() -- Finalize private state for magnetic disk storage manager.
 */
void
cassandra_shutdown(void)
{
}

/*
 *	cassandra_close() -- Close the specified relation, if it isn't closed already.
 */
void cassandra_close(SMgrRelation reln, ForkNumber forknum)
{
}

/*
 *	cassandra_create() -- Create a new relation on magnetic disk.
 *
 * If isRedo is true, it's okay for the relation to exist already.
 */
void cassandra_create(SMgrRelation reln, ForkNumber forknum, bool isRedo)
{
}

/*
 *	mdexists() -- Does the physical file exist?
 *
 * Note: this will return true for lingering files, with pending deletions
 */
bool
cassandra_exists(SMgrRelation reln, ForkNumber forknum)
{
}

/*
 *	cassandra_unlink() -- Unlink a relation.
 */
void
cassandra_unlink(RelFileNodeBackend rnode, ForkNumber forknum, bool isRedo)
{
}

/*
 *	cassandra_extend() -- Add a block to the specified relation.
 */
void
cassandra_extend(SMgrRelation reln, ForkNumber forknum, BlockNumber blocknum, char *buffer, bool skipFsync)
{
}

/*
 *	cassandra_prefetch() -- Initiate asynchronous read of the specified block of a relation
 */
void
cassandra_prefetch(SMgrRelation reln, ForkNumber forknum, BlockNumber blocknum)
{
}

/*
 *	cassandra_read() -- Read the specified block from a relation.
 */
void
cassandra_read(SMgrRelation reln, ForkNumber forknum, BlockNumber blocknum, char *buffer)
{
}

/*
 *	cassandra_write() -- Write the supplied block at the appropriate location.
 */
void
cassandra_write(SMgrRelation reln, ForkNumber forknum, BlockNumber blocknum, char *buffer, bool skipFsync)
{
}

/*
 * cassandra_writeback() -- Tell the kernel to write pages back to storage.
 *
 * This accepts a range of blocks because flushing several pages at once is
 * considerably more efficient than doing so individually.
 */
void
cassandra_writeback(SMgrRelation reln, ForkNumber forknum, BlockNumber blocknum, BlockNumber nblocks)
{
}

/*
 *	cassandra_nblocks() -- Get the number of blocks stored in a relation.
 *
 *		Important side effect: all active segments of the relation are opened
 *		and added to the mdfd_chain list.  If this routine has not been
 *		called, then only segments up to the last one actually touched
 *		are present in the chain.
 */
BlockNumber cassandra_nblocks(SMgrRelation reln, ForkNumber forknum)
{
}

/*
 *	cassandra_truncate() -- Truncate relation to specified number of blocks.
 */
void
cassandra_truncate(SMgrRelation reln, ForkNumber forknum, BlockNumber nblocks)
{
}

/*
 *	cassandra_immedsync() -- Immediately sync a relation to stable storage.
 *
 * Note that only writes already issued are synced; this routine knows
 * nothing of dirty buffers that may exist inside the buffer manager.
 */
void cassandra_immedsync(SMgrRelation reln, ForkNumber forknum)
{
}

/*
 * cassandra_pre_ckpt() -- Do pre-checkpoint work
 */
void cassandra_pre_ckpt(void);  /* may be NULL */

/*
 *	cassandra_sync() -- Sync previous writes to stable storage.
 */
void
cassandra_sync(void) /* may be NULL */
{
}

/*
 * cassandra_post_ckpt() -- Do post-checkpoint work
 */
void
cassandra_post_ckpt()  /* may be NULL */
{
}
