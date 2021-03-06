
/* This file was generated by mib2c and is intended for use as a mib module
   for the ucd-snmp snmpd agent.  Edited by Michael Baer

   last changed 2/2/99.
*/

#ifndef _MIBGROUP_SNMPTARGETADDRENTRY_H
#define _MIBGROUP_SNMPTARGETADDRENTRY_H

/* we use header_generic and checkmib from the util_funcs module */

config_require(util_funcs)

/* Magic number definitions: */

#define   SNMPTARGETADDRTDOMAIN      1
#define   SNMPTARGETADDRTADDRESS     2
#define   SNMPTARGETADDRTIMEOUT      3
#define   SNMPTARGETADDRRETRYCOUNT   4
#define   SNMPTARGETADDRTAGLIST      5
#define   SNMPTARGETADDRPARAMS       6
#define   SNMPTARGETADDRSTORAGETYPE  7
#define   SNMPTARGETADDRROWSTATUS    8

#define   SNMPTARGETADDRTDOMAINCOLUMN      2
#define   SNMPTARGETADDRTADDRESSCOLUMN     3
#define   SNMPTARGETADDRTIMEOUTCOLUMN      4
#define   SNMPTARGETADDRRETRYCOUNTCOLUMN   5
#define   SNMPTARGETADDRTAGLISTCOLUMN      6
#define   SNMPTARGETADDRPARAMSCOLUMN       7
#define   SNMPTARGETADDRSTORAGETYPECOLUMN  8
#define   SNMPTARGETADDRROWSTATUSCOLUMN    9

/* structure definitions */

struct targetAddrTable_struct {
  char  *name;
  oid    tDomain[MAX_OID_LEN];
  int    tDomainLen;
  char  *tAddress;
  int    timeout;
  int    retryCount;
  char  *tagList;
  char  *params;
  int    spinLock;
  int    storageType;
  int    rowStatus;
  struct targetAddrTable_struct *next;
};

/* function definitions */

void          init_snmpTargetAddrEntry(void);
int           store_snmpTargetAddrEntry(int majorID, int minorID,
                                        void *serverarg, void *clientarg);
FindVarMethod var_snmpTargetAddrEntry;

void snmpd_parse_config_targetAddr(const char *, char *);

WriteMethod write_snmpTargetAddrTDomain;
WriteMethod write_snmpTargetAddrTAddress;
WriteMethod write_snmpTargetAddrTimeout;
WriteMethod write_snmpTargetAddrRetryCount;
WriteMethod write_snmpTargetAddrTagList;
WriteMethod write_snmpTargetAddrParams;
WriteMethod write_snmpTargetAddrStorageType;
WriteMethod write_snmpTargetAddrRowStatus;


#endif /* _MIBGROUP_SNMPTARGETADDRENTRY_H */
