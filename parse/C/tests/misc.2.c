
#ifndef DJGPP
long smb_WriteData(smb_fid_t *fidp, osi_hyper_t *offsetp, long count, char *op,
	cm_user_t *userp, long *writtenp)
#else /* DJGPP */
long smb_WriteData(smb_fid_t *fidp, osi_hyper_t *offsetp, long count, char *op,
	cm_user_t *userp, long *writtenp, int dosflag)
#endif /* !DJGPP */
{
	osi_hyper_t offset;
