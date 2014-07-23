#ifndef GM_SCOREBOARD_H
#define GM_SCOREBOARD_H 1

#include <apr_pools.h>

/* Author: Brad Nicholes (bnicholes novell.com) */

enum ganglia_scoreboard_types {
	GSB_UNKNOWN = 0,
	GSB_COUNTER = 1,
	GSB_READ_RESET = 2,
	GSB_STATE = 3
};
typedef enum ganglia_scoreboard_types ganglia_scoreboard_types;

/* predefined gmetad scoreboard elements */
#define METS_RECVD_ALL "gmetad_metrics_recvd_all"
#define METS_SENT_ALL "gmetad_metrics_sent_all"
#define METS_SENT_RRDTOOL "gmetad_metrics_sent_rrdtool"
#define METS_SENT_RRDCACHED "gmetad_metrics_sent_rrdcached"
#define METS_SENT_GRAPHITE "gmetad_metrics_sent_graphite"
#define METS_SENT_MEMCACHED "gmetad_metrics_sent_memcached"
#define METS_SENT_RIEMANN "gmetad_metrics_sent_riemann"

#define METS_ALL_DURATION "mets_all_duration"
#define METS_RRDTOOLS_DURATION "mets_rrdtools_duration"
#define METS_RRDCACHED_DURATION "mets_rrdcached_duration"
#define METS_GRAPHITE_DURATION "mets_graphite_duration"
#define METS_MEMCACHED_DURATION "mets_memcached_duration"
#define METS_RIEMANN_DURATION "mets_riemann_duration"

#define METS_ALL_LAST_TIME "mets_all_last_time"
#define METS_RRDTOOLS_LAST_TIME "mets_rrdtools_last_time"
#define METS_RRDCACHED_LAST_TIME "mets_rrdcached_last_time"
#define METS_GRAPHITE_LAST_TIME "mets_graphite_last_time"
#define METS_MEMCACHED_LAST_TIME "mets_memcached_last_time"
#define METS_RIEMANN_LAST_TIME "mets_riemann_last_time"

#define DS_POLL_REQS "ds_poll_reqs"
#define DS_POLL_DURATION "ds_poll_duration"

#define NBR_TCP_REQS_ALL "nbr_tcp_reqs_all"
#define TIME_TCP_REQS_ALL "time_tcp_reqs_all"
#define NBR_TCP_REQS_XML "nbr_tcp_reqs_xml"
#define TIME_TCP_REQS_XML "time_tcp_reqs_xml"
#define NBR_TCP_REQS_INTXML "nbr_tcp_reqs_intxml"
#define TIME_TCP_REQS_INTXML "time_tcp_reqs_intxml"

#define METS_SUMRZ_NUM "mets_sumrz_num"
#define METS_SUMRZ_DURATION "mets_sumrz_duration"
#define METS_SUMRZ_LAST_TIME "mets_sumrz_last_time"

/*
#define INTER_IMPORTS_NBR_ALL "gmetad_internal_imports_nbr_all"
#define INTER_IMPORTS_NBR_RRDTOOLS "gmetad_internal_imports_nbr_rrdtools"
#define INTER_IMPORTS_NBR_RRDCACHED "gmetad_internal_imports_nbr_rrdcached"
#define INTER_IMPORTS_NBR_GRAPHITE "gmetad_internal_imports_nbr_graphite"
#define INTER_IMPORTS_NBR_MEMCACHED "gmetad_internal_imports_nbr_memcached"
#define INTER_IMPORTS_NBR_RIEMANN "gmetad_internal_imports_nbr_riemann"

#define INTER_IMPORTS_TIME_EXP_ALL "gmetad_internal_imports_nbr_exp_time_all"
#define INTER_IMPORTS_TIME_EXP_RRDTOOLS "gmetad_internal_imports_nbr_exp_time_rrdtools"
#define INTER_IMPORTS_TIME_EXP_RRDCACHED "gmetad_internal_imports_nbr_exp_time_rrdcached"
#define INTER_IMPORTS_TIME_EXP_GRAPHITE "gmetad_internal_imports_nbr_exp_time_graphite"
#define INTER_IMPORTS_TIME_EXP_MEMCACHED "gmetad_internal_imports_nbr_exp_time_memcached"
#define INTER_IMPORTS_TIME_EXP_RIEMANN "gmetad_internal_imports_nbr_exp_time_riemann"

#define INTER_IMPORTS_LAST_EXP_ALL "gmetad_internal_imports_nbr_last_exp_all"
#define INTER_IMPORTS_LAST_EXP_RRDTOOLS "gmetad_internal_imports_nbr_last_exp_rrdtools"
#define INTER_IMPORTS_LAST_EXP_RRDCACHED "gmetad_internal_imports_nbr_last_exp_rrdcached"
#define INTER_IMPORTS_LAST_EXP_GRAPHITE "gmetad_internal_imports_nbr_last_exp_graphite"
#define INTER_IMPORTS_LAST_EXP_MEMCACHED "gmetad_internal_imports_nbr_last_exp_memcached"
#define INTER_IMPORTS_LAST_EXP_RIEMANN "gmetad_internal_imports_nbr_last_exp_riemann"

#define INTER_LATENCY_TIME_ALL "gmetad_internal_latency_time_all"
#define INTER_LATENCY__ALL "gmetad_internal_latency__all"
*/

/* predefined gmond scoreboard elements */
#define PKTS_RECVD_ALL "gmond_pkts_recvd_all"
#define PKTS_RECVD_FAILED "gmond_pkts_recvd_failed"
#define PKTS_RECVD_IGNORED "gmond_pkts_recvd_ignored"
#define PKTS_RECVD_METADATA "gmond_pkts_recvd_metadata"
#define PKTS_RECVD_VALUE "gmond_pkts_recvd_value"
#define PKTS_RECVD_REQUEST "gmond_pkts_recvd_request"
#define PKTS_SENT_ALL "gmond_pkts_sent_all"
#define PKTS_SENT_FAILED "gmond_pkts_sent_failed"
#define PKTS_SENT_METADATA "gmond_pkts_sent_metadata"
#define PKTS_SENT_VALUE "gmond_pkts_sent_value"
#define PKTS_SENT_REQUEST "gmond_pkts_sent_request"
#define PKTS_SENT_FAILED "gmond_pkts_sent_failed"

/* The scoreboard is only enabled when --enable-status is set on configure */
#ifdef GSTATUS
void ganglia_scoreboard_init(apr_pool_t *pool);
void* ganglia_scoreboard_iterator();
char* ganglia_scoreboard_next(void **intr);
void ganglia_scoreboard_add(char *name, ganglia_scoreboard_types type);
int ganglia_scoreboard_get(char *name);
void ganglia_scoreboard_set(char *name, int val);
void ganglia_scoreboard_reset(char *name);
int ganglia_scoreboard_inc(char *name);
int ganglia_scoreboard_incby(char *name, int val);
void ganglia_scoreboard_dec(char *name);
ganglia_scoreboard_types ganglia_scoreboard_type(char *name);
#else
#define ganglia_scoreboard_init(p)
#define ganglia_scoreboard_iterator() (NULL)
#define ganglia_scoreboard_next(i) (NULL)
#define ganglia_scoreboard_add(n,t) 
#define ganglia_scoreboard_get(n) (0)
#define ganglia_scoreboard_set(n,v) 
#define ganglia_scoreboard_reset(n) 
#define ganglia_scoreboard_inc(n)
#define ganglia_scoreboard_incby(n,v)
#define ganglia_scoreboard_dec(n) 
#define ganglia_scoreboard_type(n) (GSB_UNKNOWN)
#endif

#endif /*GM_SCOREBOARD_H*/
