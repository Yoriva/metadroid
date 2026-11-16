#include "precompiled.h"

static int mm_PrecacheModel(const char* s)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheModel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(s);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPrecacheModel;
		if (_fn) {
			dllret = _fn(s);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheModel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(s);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_PrecacheSound(const char* s)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheSound;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(s);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPrecacheSound;
		if (_fn) {
			dllret = _fn(s);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheSound;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(s);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_SetModel(edict_t *e, const char *m)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetModel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e, m);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetModel;
		if (_fn) {
			_fn(e, m);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetModel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e, m);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_ModelIndex(const char *m)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnModelIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(m);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnModelIndex;
		if (_fn) {
			dllret = _fn(m);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnModelIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(m);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_ModelFrames(int modelIndex)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnModelFrames;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(modelIndex);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnModelFrames;
		if (_fn) {
			dllret = _fn(modelIndex);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnModelFrames;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(modelIndex);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_SetSize(edict_t *e, const float *rgflMin, const float *rgflMax)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetSize;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e, rgflMin, rgflMax);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetSize;
		if (_fn) {
			_fn(e, rgflMin, rgflMax);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetSize;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e, rgflMin, rgflMax);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ChangeLevel(const char* s1, const char* s2)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnChangeLevel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(s1, s2);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnChangeLevel;
		if (_fn) {
			_fn(s1, s2);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnChangeLevel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(s1, s2);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_GetSpawnParms(edict_t *ent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetSpawnParms;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetSpawnParms;
		if (_fn) {
			_fn(ent);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetSpawnParms;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SaveSpawnParms(edict_t *ent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveSpawnParms;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSaveSpawnParms;
		if (_fn) {
			_fn(ent);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveSpawnParms;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static float mm_VecToYaw(const float *rgflVector)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	float dllret{};
	float override_ret{};
	float pub_override_ret{};
	float orig_ret{};
	float pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnVecToYaw;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(rgflVector);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnVecToYaw;
		if (_fn) {
			dllret = _fn(rgflVector);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnVecToYaw;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(rgflVector);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_VecToAngles(const float *rgflVectorIn, float *rgflVectorOut)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnVecToAngles;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(rgflVectorIn, rgflVectorOut);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnVecToAngles;
		if (_fn) {
			_fn(rgflVectorIn, rgflVectorOut);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnVecToAngles;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(rgflVectorIn, rgflVectorOut);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_MoveToOrigin(edict_t *ent, const float *pflGoal, float dist, int iMoveType)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnMoveToOrigin;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent, pflGoal, dist, iMoveType);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnMoveToOrigin;
		if (_fn) {
			_fn(ent, pflGoal, dist, iMoveType);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnMoveToOrigin;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent, pflGoal, dist, iMoveType);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ChangeYaw(edict_t* ent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnChangeYaw;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnChangeYaw;
		if (_fn) {
			_fn(ent);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnChangeYaw;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ChangePitch(edict_t* ent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnChangePitch;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnChangePitch;
		if (_fn) {
			_fn(ent);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnChangePitch;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static edict_t* mm_FindEntityByString(edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindEntityByString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdictStartSearchAfter, pszField, pszValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFindEntityByString;
		if (_fn) {
			dllret = _fn(pEdictStartSearchAfter, pszField, pszValue);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindEntityByString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdictStartSearchAfter, pszField, pszValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_GetEntityIllum(edict_t* pEnt)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetEntityIllum;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEnt);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetEntityIllum;
		if (_fn) {
			dllret = _fn(pEnt);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetEntityIllum;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEnt);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static edict_t* mm_FindEntityInSphere(edict_t *pEdictStartSearchAfter, const float *org, float rad)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindEntityInSphere;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdictStartSearchAfter, org, rad);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFindEntityInSphere;
		if (_fn) {
			dllret = _fn(pEdictStartSearchAfter, org, rad);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindEntityInSphere;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdictStartSearchAfter, org, rad);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static edict_t* mm_FindClientInPVS(edict_t *pEdict)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindClientInPVS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFindClientInPVS;
		if (_fn) {
			dllret = _fn(pEdict);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindClientInPVS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static edict_t* mm_EntitiesInPVS(edict_t *pplayer)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEntitiesInPVS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pplayer);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEntitiesInPVS;
		if (_fn) {
			dllret = _fn(pplayer);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEntitiesInPVS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pplayer);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_MakeVectors(const float *rgflVector)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnMakeVectors;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(rgflVector);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnMakeVectors;
		if (_fn) {
			_fn(rgflVector);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnMakeVectors;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(rgflVector);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_AngleVectors(const float *rgflVector, float *forward, float *right, float *up)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnAngleVectors;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(rgflVector, forward, right, up);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnAngleVectors;
		if (_fn) {
			_fn(rgflVector, forward, right, up);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnAngleVectors;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(rgflVector, forward, right, up);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static edict_t* mm_CreateEntity(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCreateEntity;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_RemoveEntity(edict_t* e)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnRemoveEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnRemoveEntity;
		if (_fn) {
			_fn(e);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRemoveEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static edict_t* mm_CreateNamedEntity(int className)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateNamedEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(className);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCreateNamedEntity;
		if (_fn) {
			dllret = _fn(className);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateNamedEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(className);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_MakeStatic(edict_t *ent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnMakeStatic;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnMakeStatic;
		if (_fn) {
			_fn(ent);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnMakeStatic;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_EntIsOnFloor(edict_t *e)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEntIsOnFloor;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEntIsOnFloor;
		if (_fn) {
			dllret = _fn(e);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEntIsOnFloor;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_DropToFloor(edict_t* e)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDropToFloor;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDropToFloor;
		if (_fn) {
			dllret = _fn(e);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDropToFloor;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_WalkMove(edict_t *ent, float yaw, float dist, int iMode)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWalkMove;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(ent, yaw, dist, iMode);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWalkMove;
		if (_fn) {
			dllret = _fn(ent, yaw, dist, iMode);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWalkMove;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(ent, yaw, dist, iMode);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_SetOrigin(edict_t *e, const float *rgflOrigin)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetOrigin;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e, rgflOrigin);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetOrigin;
		if (_fn) {
			_fn(e, rgflOrigin);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetOrigin;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(e, rgflOrigin);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_EmitSound(edict_t *entity, int channel, const char *sample, /*int*/float volume, float attenuation, int fFlags, int pitch)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEmitSound;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(entity, channel, sample, volume, attenuation, fFlags, pitch);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEmitSound;
		if (_fn) {
			_fn(entity, channel, sample, volume, attenuation, fFlags, pitch);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEmitSound;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(entity, channel, sample, volume, attenuation, fFlags, pitch);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_EmitAmbientSound(edict_t *entity, float *pos, const char *samp, float vol, float attenuation, int fFlags, int pitch)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEmitAmbientSound;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(entity, pos, samp, vol, attenuation, fFlags, pitch);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEmitAmbientSound;
		if (_fn) {
			_fn(entity, pos, samp, vol, attenuation, fFlags, pitch);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEmitAmbientSound;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(entity, pos, samp, vol, attenuation, fFlags, pitch);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static unsigned int mm_trace_diag = 0;

static void mm_TraceLine(const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr)
{
	const double dx = v2[0] - v1[0], dy = v2[1] - v1[1], dz = v2[2] - v1[2];
	const bool bulletTrace = (dx * dx + dy * dy + dz * dz) > 3000.0 * 3000.0;
	const bool diag = mm_trace_diag < 5000 && fNoMonsters == 0 && bulletTrace;
	if (diag) mm_trace_diag++;
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (diag) {
		int skipIdx = pentToSkip ? ENTINDEX(pentToSkip) : -1;
		ALERT(at_logged, "[mm-diag] TraceLine in fNoMonsters=%d idx=%d v1=(%.1f %.1f %.1f) v2=(%.1f %.1f %.1f)\n",
			fNoMonsters, skipIdx, v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceLine;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, fNoMonsters, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTraceLine;
		if (_fn) {
			_fn(v1, v2, fNoMonsters, pentToSkip, ptr);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceLine;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, fNoMonsters, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (diag) {
		int hitIdx = (ptr && ptr->pHit) ? ENTINDEX(ptr->pHit) : -1;
		ALERT(at_logged, "[mm-diag] TraceLine out flFraction=%.4f iHitgroup=%d pHitIdx=%d\n",
			ptr ? ptr->flFraction : -1.0f, ptr ? ptr->iHitgroup : -1, hitIdx);
	}
	g_metaGlobals = backup;
}

static void mm_TraceToss(edict_t* pent, edict_t* pentToIgnore, TraceResult *ptr)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceToss;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent, pentToIgnore, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTraceToss;
		if (_fn) {
			_fn(pent, pentToIgnore, ptr);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceToss;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent, pentToIgnore, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_TraceMonsterHull(edict_t *pEdict, const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceMonsterHull;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict, v1, v2, fNoMonsters, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTraceMonsterHull;
		if (_fn) {
			dllret = _fn(pEdict, v1, v2, fNoMonsters, pentToSkip, ptr);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceMonsterHull;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict, v1, v2, fNoMonsters, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_TraceHull(const float *v1, const float *v2, int fNoMonsters, int hullNumber, edict_t *pentToSkip, TraceResult *ptr)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceHull;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, fNoMonsters, hullNumber, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTraceHull;
		if (_fn) {
			_fn(v1, v2, fNoMonsters, hullNumber, pentToSkip, ptr);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceHull;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, fNoMonsters, hullNumber, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_TraceModel(const float *v1, const float *v2, int hullNumber, edict_t *pent, TraceResult *ptr)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceModel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, hullNumber, pent, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTraceModel;
		if (_fn) {
			_fn(v1, v2, hullNumber, pent, ptr);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceModel;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, hullNumber, pent, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static const char * mm_TraceTexture(edict_t *pTextureEntity, const float *v1, const float *v2)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceTexture;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pTextureEntity, v1, v2);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTraceTexture;
		if (_fn) {
			dllret = _fn(pTextureEntity, v1, v2);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceTexture;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pTextureEntity, v1, v2);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_TraceSphere(const float *v1, const float *v2, int fNoMonsters, float radius, edict_t *pentToSkip, TraceResult *ptr)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceSphere;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, fNoMonsters, radius, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTraceSphere;
		if (_fn) {
			_fn(v1, v2, fNoMonsters, radius, pentToSkip, ptr);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTraceSphere;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(v1, v2, fNoMonsters, radius, pentToSkip, ptr);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_GetAimVector(edict_t* ent, float speed, float *rgflReturn)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetAimVector;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent, speed, rgflReturn);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetAimVector;
		if (_fn) {
			_fn(ent, speed, rgflReturn);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetAimVector;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent, speed, rgflReturn);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ServerCommand(const char* str)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(str);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnServerCommand;
		if (_fn) {
			_fn(str);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(str);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ServerExecute(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerExecute;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnServerExecute;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerExecute;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ParticleEffect(const float *org, const float *dir, float color, float count)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnParticleEffect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(org, dir, color, count);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnParticleEffect;
		if (_fn) {
			_fn(org, dir, color, count);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnParticleEffect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(org, dir, color, count);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_LightStyle(int style, const char* val)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnLightStyle;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(style, val);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnLightStyle;
		if (_fn) {
			_fn(style, val);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnLightStyle;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(style, val);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_DecalIndex(const char *name)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDecalIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(name);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDecalIndex;
		if (_fn) {
			dllret = _fn(name);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDecalIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(name);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_PointContents(const float *rgflVector)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPointContents;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(rgflVector);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPointContents;
		if (_fn) {
			dllret = _fn(rgflVector);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPointContents;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(rgflVector);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_MessageBegin(int msg_dest, int msg_type, const float *pOrigin, edict_t *ed)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnMessageBegin;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(msg_dest, msg_type, pOrigin, ed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnMessageBegin;
		if (_fn) {
			_fn(msg_dest, msg_type, pOrigin, ed);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnMessageBegin;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(msg_dest, msg_type, pOrigin, ed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_MessageEnd(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnMessageEnd;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnMessageEnd;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnMessageEnd;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteByte(int iValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteByte;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteByte;
		if (_fn) {
			_fn(iValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteByte;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteChar(int iValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteChar;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteChar;
		if (_fn) {
			_fn(iValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteChar;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteShort(int iValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteShort;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteShort;
		if (_fn) {
			_fn(iValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteShort;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteLong(int iValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteLong;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteLong;
		if (_fn) {
			_fn(iValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteLong;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteAngle(float flValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteAngle;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(flValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteAngle;
		if (_fn) {
			_fn(flValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteAngle;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(flValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteCoord(float flValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteCoord;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(flValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteCoord;
		if (_fn) {
			_fn(flValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteCoord;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(flValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteString(const char *sz)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(sz);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteString;
		if (_fn) {
			_fn(sz);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(sz);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_WriteEntity(int iValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnWriteEntity;
		if (_fn) {
			_fn(iValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnWriteEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(iValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_CVarRegister(cvar_t *pCvar)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarRegister;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pCvar);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCVarRegister;
		if (_fn) {
			_fn(pCvar);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarRegister;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pCvar);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static float mm_CVarGetFloat(const char *szVarName)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	float dllret{};
	float override_ret{};
	float pub_override_ret{};
	float orig_ret{};
	float pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarGetFloat;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szVarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCVarGetFloat;
		if (_fn) {
			dllret = _fn(szVarName);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarGetFloat;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szVarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static const char * mm_CVarGetString(const char *szVarName)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarGetString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szVarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCVarGetString;
		if (_fn) {
			dllret = _fn(szVarName);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarGetString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szVarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_CVarSetFloat(const char *szVarName, float flValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarSetFloat;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szVarName, flValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCVarSetFloat;
		if (_fn) {
			_fn(szVarName, flValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarSetFloat;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szVarName, flValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_CVarSetString(const char *szVarName, const char *szValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarSetString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szVarName, szValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCVarSetString;
		if (_fn) {
			_fn(szVarName, szValue);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarSetString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szVarName, szValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void* mm_PvAllocEntPrivateData(edict_t *pEdict, int32 cb)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	void* dllret{};
	void* override_ret{};
	void* pub_override_ret{};
	void* orig_ret{};
	void* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPvAllocEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict, cb);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPvAllocEntPrivateData;
		if (_fn) {
			dllret = _fn(pEdict, cb);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPvAllocEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict, cb);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void* mm_PvEntPrivateData(edict_t *pEdict)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	void* dllret{};
	void* override_ret{};
	void* pub_override_ret{};
	void* orig_ret{};
	void* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPvEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPvEntPrivateData;
		if (_fn) {
			dllret = _fn(pEdict);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPvEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_FreeEntPrivateData(edict_t *pEdict)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFreeEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFreeEntPrivateData;
		if (_fn) {
			_fn(pEdict);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFreeEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static const char * mm_SzFromIndex(int iString)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSzFromIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iString);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSzFromIndex;
		if (_fn) {
			dllret = _fn(iString);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSzFromIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iString);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_AllocString(const char *szValue)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnAllocString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnAllocString;
		if (_fn) {
			dllret = _fn(szValue);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnAllocString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szValue);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static struct entvars_s* mm_GetVarsOfEnt(edict_t *pEdict)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	struct entvars_s* dllret{};
	struct entvars_s* override_ret{};
	struct entvars_s* pub_override_ret{};
	struct entvars_s* orig_ret{};
	struct entvars_s* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetVarsOfEnt;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetVarsOfEnt;
		if (_fn) {
			dllret = _fn(pEdict);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetVarsOfEnt;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static edict_t* mm_PEntityOfEntOffset(int iEntOffset)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPEntityOfEntOffset;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iEntOffset);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPEntityOfEntOffset;
		if (_fn) {
			dllret = _fn(iEntOffset);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPEntityOfEntOffset;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iEntOffset);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_EntOffsetOfPEntity(const edict_t *pEdict)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEntOffsetOfPEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEntOffsetOfPEntity;
		if (_fn) {
			dllret = _fn(pEdict);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEntOffsetOfPEntity;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_IndexOfEdict(const edict_t *pEdict)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnIndexOfEdict;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnIndexOfEdict;
		if (_fn) {
			dllret = _fn(pEdict);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnIndexOfEdict;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static edict_t* mm_PEntityOfEntIndex(int iEntIndex)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPEntityOfEntIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iEntIndex);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPEntityOfEntIndex;
		if (_fn) {
			dllret = _fn(iEntIndex);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPEntityOfEntIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iEntIndex);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static edict_t* mm_FindEntityByVars(struct entvars_s* pvars)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t* dllret{};
	edict_t* override_ret{};
	edict_t* pub_override_ret{};
	edict_t* orig_ret{};
	edict_t* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindEntityByVars;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pvars);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFindEntityByVars;
		if (_fn) {
			dllret = _fn(pvars);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFindEntityByVars;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pvars);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void* mm_GetModelPtr(edict_t* pEdict)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	void* dllret{};
	void* override_ret{};
	void* pub_override_ret{};
	void* orig_ret{};
	void* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetModelPtr;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetModelPtr;
		if (_fn) {
			dllret = _fn(pEdict);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetModelPtr;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEdict);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_AnimationAutomove(const edict_t* pEdict, float flTime)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnAnimationAutomove;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, flTime);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnAnimationAutomove;
		if (_fn) {
			_fn(pEdict, flTime);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnAnimationAutomove;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, flTime);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_GetBonePosition(const edict_t* pEdict, int iBone, float *rgflOrigin, float *rgflAngles)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetBonePosition;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, iBone, rgflOrigin, rgflAngles);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetBonePosition;
		if (_fn) {
			_fn(pEdict, iBone, rgflOrigin, rgflAngles);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetBonePosition;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, iBone, rgflOrigin, rgflAngles);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static uint32 mm_FunctionFromName(const char *pName)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	uint32 dllret{};
	uint32 override_ret{};
	uint32 pub_override_ret{};
	uint32 orig_ret{};
	uint32 pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFunctionFromName;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFunctionFromName;
		if (_fn) {
			dllret = _fn(pName);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFunctionFromName;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static const char * mm_NameForFunction(uint32 function)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnNameForFunction;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(function);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnNameForFunction;
		if (_fn) {
			dllret = _fn(function);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnNameForFunction;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(function);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_ClientPrintf(edict_t* pEdict, PRINT_TYPE ptype, const char *szMsg)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientPrintf;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, ptype, szMsg);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnClientPrintf;
		if (_fn) {
			_fn(pEdict, ptype, szMsg);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientPrintf;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, ptype, szMsg);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ServerPrint(const char *szMsg)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerPrint;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szMsg);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnServerPrint;
		if (_fn) {
			_fn(szMsg);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerPrint;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szMsg);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static const char * mm_Cmd_Args(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmd_Args;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCmd_Args;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmd_Args;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static const char * mm_Cmd_Argv(int argc)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmd_Argv;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(argc);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCmd_Argv;
		if (_fn) {
			dllret = _fn(argc);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmd_Argv;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(argc);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_Cmd_Argc(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmd_Argc;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCmd_Argc;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmd_Argc;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_GetAttachment(const edict_t *pEdict, int iAttachment, float *rgflOrigin, float *rgflAngles)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetAttachment;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, iAttachment, rgflOrigin, rgflAngles);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetAttachment;
		if (_fn) {
			_fn(pEdict, iAttachment, rgflOrigin, rgflAngles);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetAttachment;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, iAttachment, rgflOrigin, rgflAngles);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_CRC32_Init(CRC32_t *pulCRC)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_Init;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pulCRC);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCRC32_Init;
		if (_fn) {
			_fn(pulCRC);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_Init;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pulCRC);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_CRC32_ProcessBuffer(CRC32_t *pulCRC, void *p, int len)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_ProcessBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pulCRC, p, len);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCRC32_ProcessBuffer;
		if (_fn) {
			_fn(pulCRC, p, len);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_ProcessBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pulCRC, p, len);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_CRC32_ProcessByte(CRC32_t *pulCRC, unsigned char ch)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_ProcessByte;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pulCRC, ch);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCRC32_ProcessByte;
		if (_fn) {
			_fn(pulCRC, ch);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_ProcessByte;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pulCRC, ch);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static CRC32_t mm_CRC32_Final(CRC32_t pulCRC)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	CRC32_t dllret{};
	CRC32_t override_ret{};
	CRC32_t pub_override_ret{};
	CRC32_t orig_ret{};
	CRC32_t pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_Final;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pulCRC);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCRC32_Final;
		if (_fn) {
			dllret = _fn(pulCRC);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCRC32_Final;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pulCRC);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int32 mm_RandomLong(int32  lLow,  int32  lHigh)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int32 dllret{};
	int32 override_ret{};
	int32 pub_override_ret{};
	int32 orig_ret{};
	int32 pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnRandomLong;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(lLow, lHigh);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnRandomLong;
		if (_fn) {
			dllret = _fn(lLow, lHigh);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRandomLong;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(lLow, lHigh);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static float mm_RandomFloat(float flLow, float flHigh)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	float dllret{};
	float override_ret{};
	float pub_override_ret{};
	float orig_ret{};
	float pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnRandomFloat;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(flLow, flHigh);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnRandomFloat;
		if (_fn) {
			dllret = _fn(flLow, flHigh);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRandomFloat;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(flLow, flHigh);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_SetView(const edict_t *pClient, const edict_t *pViewent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetView;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, pViewent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetView;
		if (_fn) {
			_fn(pClient, pViewent);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetView;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, pViewent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static float mm_Time(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	float dllret{};
	float override_ret{};
	float pub_override_ret{};
	float orig_ret{};
	float pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnTime;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnTime;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTime;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_CrosshairAngle(const edict_t *pClient, float pitch, float yaw)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCrosshairAngle;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, pitch, yaw);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCrosshairAngle;
		if (_fn) {
			_fn(pClient, pitch, yaw);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCrosshairAngle;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, pitch, yaw);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static byte * mm_LoadFileForMe(const char *filename, int *pLength)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	byte * dllret{};
	byte * override_ret{};
	byte * pub_override_ret{};
	byte * orig_ret{};
	byte * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnLoadFileForMe;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename, pLength);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnLoadFileForMe;
		if (_fn) {
			dllret = _fn(filename, pLength);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnLoadFileForMe;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename, pLength);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_FreeFile(void *buffer)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFreeFile;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(buffer);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFreeFile;
		if (_fn) {
			_fn(buffer);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFreeFile;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(buffer);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_EndSection(const char *pszSectionName)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEndSection;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pszSectionName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEndSection;
		if (_fn) {
			_fn(pszSectionName);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEndSection;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pszSectionName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_CompareFileTime(char *filename1, char *filename2, int *iCompare)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCompareFileTime;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename1, filename2, iCompare);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCompareFileTime;
		if (_fn) {
			dllret = _fn(filename1, filename2, iCompare);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCompareFileTime;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename1, filename2, iCompare);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_GetGameDir(char *szGetGameDir)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetGameDir;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szGetGameDir);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetGameDir;
		if (_fn) {
			_fn(szGetGameDir);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetGameDir;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(szGetGameDir);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_Cvar_RegisterVariable(cvar_t *variable)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvar_RegisterVariable;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(variable);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCvar_RegisterVariable;
		if (_fn) {
			_fn(variable);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvar_RegisterVariable;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(variable);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_FadeClientVolume(const edict_t *pEdict, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnFadeClientVolume;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, fadePercent, fadeOutSeconds, holdTime, fadeInSeconds);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnFadeClientVolume;
		if (_fn) {
			_fn(pEdict, fadePercent, fadeOutSeconds, holdTime, fadeInSeconds);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnFadeClientVolume;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, fadePercent, fadeOutSeconds, holdTime, fadeInSeconds);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SetClientMaxspeed(edict_t *pEdict, float fNewMaxspeed)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetClientMaxspeed;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, fNewMaxspeed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetClientMaxspeed;
		if (_fn) {
			_fn(pEdict, fNewMaxspeed);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetClientMaxspeed;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, fNewMaxspeed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static edict_t * mm_CreateFakeClient(const char *netname)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	edict_t * dllret{};
	edict_t * override_ret{};
	edict_t * pub_override_ret{};
	edict_t * orig_ret{};
	edict_t * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateFakeClient;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(netname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCreateFakeClient;
		if (_fn) {
			dllret = _fn(netname);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateFakeClient;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(netname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_RunPlayerMove(edict_t *fakeclient, const float *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, byte impulse, byte msec)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnRunPlayerMove;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(fakeclient, viewangles, forwardmove, sidemove, upmove, buttons, impulse, msec);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnRunPlayerMove;
		if (_fn) {
			_fn(fakeclient, viewangles, forwardmove, sidemove, upmove, buttons, impulse, msec);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRunPlayerMove;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(fakeclient, viewangles, forwardmove, sidemove, upmove, buttons, impulse, msec);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_NumberOfEntities(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnNumberOfEntities;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnNumberOfEntities;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnNumberOfEntities;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static char* mm_GetInfoKeyBuffer(edict_t *e)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	char* dllret{};
	char* override_ret{};
	char* pub_override_ret{};
	char* orig_ret{};
	char* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetInfoKeyBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetInfoKeyBuffer;
		if (_fn) {
			dllret = _fn(e);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetInfoKeyBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static char* mm_InfoKeyValue(char *infobuffer, const char *key)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	char* dllret{};
	char* override_ret{};
	char* pub_override_ret{};
	char* orig_ret{};
	char* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnInfoKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(infobuffer, key);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnInfoKeyValue;
		if (_fn) {
			dllret = _fn(infobuffer, key);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnInfoKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(infobuffer, key);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_SetKeyValue(char *infobuffer, const char *key, const char *value)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(infobuffer, key, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetKeyValue;
		if (_fn) {
			_fn(infobuffer, key, value);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(infobuffer, key, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SetClientKeyValue(int clientIndex, char *infobuffer, const char *key, const char *value)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetClientKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(clientIndex, infobuffer, key, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetClientKeyValue;
		if (_fn) {
			_fn(clientIndex, infobuffer, key, value);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetClientKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(clientIndex, infobuffer, key, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_IsMapValid(const char *filename)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnIsMapValid;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnIsMapValid;
		if (_fn) {
			dllret = _fn(filename);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnIsMapValid;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_StaticDecal(const float *origin, int decalIndex, int entityIndex, int modelIndex)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnStaticDecal;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(origin, decalIndex, entityIndex, modelIndex);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnStaticDecal;
		if (_fn) {
			_fn(origin, decalIndex, entityIndex, modelIndex);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnStaticDecal;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(origin, decalIndex, entityIndex, modelIndex);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_PrecacheGeneric(const char* s)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheGeneric;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(s);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPrecacheGeneric;
		if (_fn) {
			dllret = _fn(s);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheGeneric;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(s);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_GetPlayerUserId(edict_t *e)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerUserId;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetPlayerUserId;
		if (_fn) {
			dllret = _fn(e);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerUserId;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_BuildSoundMsg(edict_t *entity, int channel, const char *sample, /*int*/float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, edict_t *ed)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnBuildSoundMsg;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(entity, channel, sample, volume, attenuation, fFlags, pitch, msg_dest, msg_type, pOrigin, ed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnBuildSoundMsg;
		if (_fn) {
			_fn(entity, channel, sample, volume, attenuation, fFlags, pitch, msg_dest, msg_type, pOrigin, ed);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnBuildSoundMsg;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(entity, channel, sample, volume, attenuation, fFlags, pitch, msg_dest, msg_type, pOrigin, ed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_IsDedicatedServer(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnIsDedicatedServer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnIsDedicatedServer;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnIsDedicatedServer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static cvar_t * mm_CVarGetPointer(const char *szVarName)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	cvar_t * dllret{};
	cvar_t * override_ret{};
	cvar_t * pub_override_ret{};
	cvar_t * orig_ret{};
	cvar_t * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarGetPointer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szVarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCVarGetPointer;
		if (_fn) {
			dllret = _fn(szVarName);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCVarGetPointer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(szVarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static unsigned int mm_GetPlayerWONId(edict_t *e)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	unsigned int dllret{};
	unsigned int override_ret{};
	unsigned int pub_override_ret{};
	unsigned int orig_ret{};
	unsigned int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerWONId;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetPlayerWONId;
		if (_fn) {
			dllret = _fn(e);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerWONId;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_Info_RemoveKey(char *s, const char *key)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnInfo_RemoveKey;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(s, key);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnInfo_RemoveKey;
		if (_fn) {
			_fn(s, key);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnInfo_RemoveKey;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(s, key);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static const char * mm_GetPhysicsKeyValue(const edict_t *pClient, const char *key)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPhysicsKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pClient, key);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetPhysicsKeyValue;
		if (_fn) {
			dllret = _fn(pClient, key);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPhysicsKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pClient, key);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_SetPhysicsKeyValue(const edict_t *pClient, const char *key, const char *value)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetPhysicsKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, key, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetPhysicsKeyValue;
		if (_fn) {
			_fn(pClient, key, value);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetPhysicsKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, key, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static const char * mm_GetPhysicsInfoString(const edict_t *pClient)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPhysicsInfoString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pClient);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetPhysicsInfoString;
		if (_fn) {
			dllret = _fn(pClient);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPhysicsInfoString;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pClient);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static unsigned short mm_PrecacheEvent(int type, const char*psz)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	unsigned short dllret{};
	unsigned short override_ret{};
	unsigned short pub_override_ret{};
	unsigned short orig_ret{};
	unsigned short pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheEvent;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(type, psz);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPrecacheEvent;
		if (_fn) {
			dllret = _fn(type, psz);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPrecacheEvent;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(type, psz);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_PlaybackEvent(int flags, const edict_t *pInvoker, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlaybackEvent;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(flags, pInvoker, eventindex, delay, origin, angles, fparam1, fparam2, iparam1, iparam2, bparam1, bparam2);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnPlaybackEvent;
		if (_fn) {
			_fn(flags, pInvoker, eventindex, delay, origin, angles, fparam1, fparam2, iparam1, iparam2, bparam1, bparam2);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlaybackEvent;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(flags, pInvoker, eventindex, delay, origin, angles, fparam1, fparam2, iparam1, iparam2, bparam1, bparam2);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static unsigned char * mm_SetFatPVS(float *org)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	unsigned char * dllret{};
	unsigned char * override_ret{};
	unsigned char * pub_override_ret{};
	unsigned char * orig_ret{};
	unsigned char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetFatPVS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(org);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetFatPVS;
		if (_fn) {
			dllret = _fn(org);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetFatPVS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(org);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static unsigned char * mm_SetFatPAS(float *org)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	unsigned char * dllret{};
	unsigned char * override_ret{};
	unsigned char * pub_override_ret{};
	unsigned char * orig_ret{};
	unsigned char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetFatPAS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(org);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetFatPAS;
		if (_fn) {
			dllret = _fn(org);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetFatPAS;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(org);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_CheckVisibility(edict_t *entity, unsigned char *pset)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCheckVisibility;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(entity, pset);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCheckVisibility;
		if (_fn) {
			dllret = _fn(entity, pset);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCheckVisibility;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(entity, pset);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_DeltaSetField(struct delta_s *pFields, const char *fieldname)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaSetField;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDeltaSetField;
		if (_fn) {
			_fn(pFields, fieldname);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaSetField;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_DeltaUnsetField(struct delta_s *pFields, const char *fieldname)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaUnsetField;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDeltaUnsetField;
		if (_fn) {
			_fn(pFields, fieldname);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaUnsetField;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_GetCurrentPlayer(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetCurrentPlayer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetCurrentPlayer;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetCurrentPlayer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_CanSkipPlayer(const edict_t *player)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCanSkipPlayer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(player);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCanSkipPlayer;
		if (_fn) {
			dllret = _fn(player);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCanSkipPlayer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(player);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_DeltaFindField(struct delta_s *pFields, const char *fieldname)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaFindField;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pFields, fieldname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDeltaFindField;
		if (_fn) {
			dllret = _fn(pFields, fieldname);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaFindField;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pFields, fieldname);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_DeltaSetFieldByIndex(struct delta_s *pFields, int fieldNumber)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaSetFieldByIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldNumber);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDeltaSetFieldByIndex;
		if (_fn) {
			_fn(pFields, fieldNumber);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaSetFieldByIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldNumber);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_DeltaUnsetFieldByIndex(struct delta_s *pFields, int fieldNumber)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaUnsetFieldByIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldNumber);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDeltaUnsetFieldByIndex;
		if (_fn) {
			_fn(pFields, fieldNumber);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaUnsetFieldByIndex;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pFields, fieldNumber);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SetGroupMask(int mask, int op)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetGroupMask;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(mask, op);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSetGroupMask;
		if (_fn) {
			_fn(mask, op);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetGroupMask;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(mask, op);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_CreateInstancedBaseline(int classname, struct entity_state_s *baseline)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateInstancedBaseline;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(classname, baseline);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCreateInstancedBaseline;
		if (_fn) {
			dllret = _fn(classname, baseline);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateInstancedBaseline;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(classname, baseline);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_Cvar_DirectSet(struct cvar_s *var, const char *value)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvar_DirectSet;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(var, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnCvar_DirectSet;
		if (_fn) {
			_fn(var, value);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvar_DirectSet;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(var, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ForceUnmodified(FORCE_TYPE type, float *mins, float *maxs, const char *filename)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnForceUnmodified;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(type, mins, maxs, filename);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnForceUnmodified;
		if (_fn) {
			_fn(type, mins, maxs, filename);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnForceUnmodified;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(type, mins, maxs, filename);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_GetPlayerStats(const edict_t *pClient, int *ping, int *packet_loss)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerStats;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, ping, packet_loss);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetPlayerStats;
		if (_fn) {
			_fn(pClient, ping, packet_loss);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerStats;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pClient, ping, packet_loss);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static qboolean mm_Voice_GetClientListening(int iReceiver, int iSender)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	qboolean dllret{};
	qboolean override_ret{};
	qboolean pub_override_ret{};
	qboolean orig_ret{};
	qboolean pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnVoice_GetClientListening;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iReceiver, iSender);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnVoice_GetClientListening;
		if (_fn) {
			dllret = _fn(iReceiver, iSender);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnVoice_GetClientListening;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iReceiver, iSender);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static qboolean mm_Voice_SetClientListening(int iReceiver, int iSender, qboolean bListen)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	qboolean dllret{};
	qboolean override_ret{};
	qboolean pub_override_ret{};
	qboolean orig_ret{};
	qboolean pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnVoice_SetClientListening;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iReceiver, iSender, bListen);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnVoice_SetClientListening;
		if (_fn) {
			dllret = _fn(iReceiver, iSender, bListen);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnVoice_SetClientListening;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(iReceiver, iSender, bListen);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static const char * mm_GetPlayerAuthId(edict_t *e)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	const char * dllret{};
	const char * override_ret{};
	const char * pub_override_ret{};
	const char * orig_ret{};
	const char * pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerAuthId;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetPlayerAuthId;
		if (_fn) {
			dllret = _fn(e);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetPlayerAuthId;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(e);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static sequenceEntry_s* mm_SequenceGet(const char* fileName, const char* entryName)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	sequenceEntry_s* dllret{};
	sequenceEntry_s* override_ret{};
	sequenceEntry_s* pub_override_ret{};
	sequenceEntry_s* orig_ret{};
	sequenceEntry_s* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSequenceGet;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(fileName, entryName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSequenceGet;
		if (_fn) {
			dllret = _fn(fileName, entryName);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSequenceGet;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(fileName, entryName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static sentenceEntry_s* mm_SequencePickSentence(const char* groupName, int pickMethod, int *picked)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	sentenceEntry_s* dllret{};
	sentenceEntry_s* override_ret{};
	sentenceEntry_s* pub_override_ret{};
	sentenceEntry_s* orig_ret{};
	sentenceEntry_s* pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnSequencePickSentence;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(groupName, pickMethod, picked);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnSequencePickSentence;
		if (_fn) {
			dllret = _fn(groupName, pickMethod, picked);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSequencePickSentence;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(groupName, pickMethod, picked);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_GetFileSize(const char *filename)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetFileSize;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetFileSize;
		if (_fn) {
			dllret = _fn(filename);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetFileSize;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filename);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static unsigned int mm_GetApproxWavePlayLen(const char *filepath)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	unsigned int dllret{};
	unsigned int override_ret{};
	unsigned int pub_override_ret{};
	unsigned int orig_ret{};
	unsigned int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetApproxWavePlayLen;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filepath);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetApproxWavePlayLen;
		if (_fn) {
			dllret = _fn(filepath);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetApproxWavePlayLen;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(filepath);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_IsCareerMatch(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnIsCareerMatch;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnIsCareerMatch;
		if (_fn) {
			dllret = _fn();
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnIsCareerMatch;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static int mm_GetLocalizedStringLength(const char *label)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetLocalizedStringLength;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(label);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetLocalizedStringLength;
		if (_fn) {
			dllret = _fn(label);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetLocalizedStringLength;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(label);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_RegisterTutorMessageShown(int mid)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnRegisterTutorMessageShown;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(mid);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnRegisterTutorMessageShown;
		if (_fn) {
			_fn(mid);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRegisterTutorMessageShown;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(mid);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_GetTimesTutorMessageShown(int mid)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetTimesTutorMessageShown;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(mid);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnGetTimesTutorMessageShown;
		if (_fn) {
			dllret = _fn(mid);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetTimesTutorMessageShown;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(mid);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_ProcessTutorMessageDecayBuffer(int *buffer, int bufferLength)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnProcessTutorMessageDecayBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(buffer, bufferLength);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnProcessTutorMessageDecayBuffer;
		if (_fn) {
			_fn(buffer, bufferLength);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnProcessTutorMessageDecayBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(buffer, bufferLength);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ConstructTutorMessageDecayBuffer(int *buffer, int bufferLength)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnConstructTutorMessageDecayBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(buffer, bufferLength);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnConstructTutorMessageDecayBuffer;
		if (_fn) {
			_fn(buffer, bufferLength);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnConstructTutorMessageDecayBuffer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(buffer, bufferLength);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ResetTutorMessageDecayData(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnResetTutorMessageDecayData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnResetTutorMessageDecayData;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnResetTutorMessageDecayData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn();
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_QueryClientCvarValue2(const edict_t *player, const char *cvarName, int requestID)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnQueryClientCvarValue2;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player, cvarName, requestID);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnQueryClientCvarValue2;
		if (_fn) {
			_fn(player, cvarName, requestID);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnQueryClientCvarValue2;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player, cvarName, requestID);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_EngCheckParm(const char *pchCmdLineToken, char **ppnext)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret{};
	int override_ret{};
	int pub_override_ret{};
	int orig_ret{};
	int pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEngCheckParm;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pchCmdLineToken, ppnext);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEngCheckParm;
		if (_fn) {
			dllret = _fn(pchCmdLineToken, ppnext);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEngCheckParm;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pchCmdLineToken, ppnext);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

static void mm_QueryClientCvarValue(const edict_t *pEdict, const char *cvarName)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	g_players.set_player_cvar_query(pEdict, cvarName);
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnQueryClientCvarValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, cvarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnQueryClientCvarValue;
		if (_fn)
			_fn(pEdict, cvarName);
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnQueryClientCvarValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, cvarName);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

// int -> void
static int mm_RegUserMsg(const char *pszName, int iSize)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	int dllret = 0, override_ret = 0, pub_override_ret = 0, orig_ret = 0, pub_orig_ret = 0;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnRegUserMsg;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pszName, iSize);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnRegUserMsg;
		if (_fn)
			dllret = _fn(pszName, iSize);
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	const int imsgid = (status == MRES_OVERRIDE) ? override_ret : orig_ret;
	auto nmsg = g_regMsgs->find(imsgid);

	if (nmsg) {
		if (!Q_strcmp(pszName, nmsg->getname()))
			META_DEBUG(3, "user message registered again: name=%s, msgid=%d", pszName, imsgid);
		else
			META_ERROR("user message id reused: msgid=%d, oldname=%s, newname=%s", imsgid, nmsg->getname(), pszName);
	}
	else
		g_regMsgs->add(pszName, imsgid, iSize);

	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRegUserMsg;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pszName, iSize);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_OVERRIDE) override_ret = pub_override_ret = dllret;
	}
	g_metaGlobals = backup;
	return (status == MRES_OVERRIDE) ? override_ret : orig_ret;
}

// printf-style functions
static void mm_engClientCommand(edict_t *pEdict, const char *szFmt, ...)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	char buf[MAX_STRBUF_LEN];
	va_list ap;
	va_start(ap, szFmt);
	Q_vsnprintf(buf, sizeof(buf), szFmt, ap);
	va_end(ap);
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, "%s", buf);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnClientCommand;
		if (_fn)
			_fn(pEdict, "%s", buf);
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdict, "%s", buf);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_AlertMessage(ALERT_TYPE atype, const char *szFmt, ...)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	char buf[MAX_STRBUF_LEN];
	va_list ap;
	va_start(ap, szFmt);
	Q_vsnprintf(buf, sizeof(buf), szFmt, ap);
	va_end(ap);
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnAlertMessage;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(atype, "%s", buf);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnAlertMessage;
		if (_fn)
			_fn(atype, "%s", buf);
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnAlertMessage;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(atype, "%s", buf);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_EngineFprintf(void *pfile, const char *szFmt, ...)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	char buf[MAX_STRBUF_LEN];
	va_list ap;
	va_start(ap, szFmt);
	Q_vsnprintf(buf, sizeof(buf), szFmt, ap);
	va_end(ap);
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnEngineFprintf;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pfile, "%s", buf);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnEngineFprintf;
		if (_fn)
			_fn(pfile, "%s", buf);
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnEngineFprintf;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pfile, "%s", buf);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_DeltaAddEncoder(const char *name, void (*conditionalencode)(struct delta_s *pFields, const unsigned char *from, const unsigned char *to))
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaAddEncoder;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(name, conditionalencode);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnDeltaAddEncoder;
		if (_fn)
			_fn(name, conditionalencode);
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnDeltaAddEncoder;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(name, conditionalencode);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_AddServerCommand(const char *cmd_name, void (*function)(void))
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_table;
		if (!_t) continue;
		auto _fn = _t->pfnAddServerCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(cmd_name, function);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE) {
		auto _fn = g_engfuncs.pfnAddServerCommand;
		if (_fn)
			_fn(cmd_name, function);
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_engine_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnAddServerCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(cmd_name, function);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}
enginefuncs_t g_meta_engfuncs =
{
	mm_PrecacheModel,
	mm_PrecacheSound,
	mm_SetModel,
	mm_ModelIndex,
	mm_ModelFrames,
	mm_SetSize,
	mm_ChangeLevel,
	mm_GetSpawnParms,
	mm_SaveSpawnParms,
	mm_VecToYaw,
	mm_VecToAngles,
	mm_MoveToOrigin,
	mm_ChangeYaw,
	mm_ChangePitch,
	mm_FindEntityByString,
	mm_GetEntityIllum,
	mm_FindEntityInSphere,
	mm_FindClientInPVS,
	mm_EntitiesInPVS,
	mm_MakeVectors,
	mm_AngleVectors,
	mm_CreateEntity,
	mm_RemoveEntity,
	mm_CreateNamedEntity,
	mm_MakeStatic,
	mm_EntIsOnFloor,
	mm_DropToFloor,
	mm_WalkMove,
	mm_SetOrigin,
	mm_EmitSound,
	mm_EmitAmbientSound,
	mm_TraceLine,
	mm_TraceToss,
	mm_TraceMonsterHull,
	mm_TraceHull,
	mm_TraceModel,
	mm_TraceTexture,
	mm_TraceSphere,
	mm_GetAimVector,
	mm_ServerCommand,
	mm_ServerExecute,
	mm_engClientCommand,
	mm_ParticleEffect,
	mm_LightStyle,
	mm_DecalIndex,
	mm_PointContents,
	mm_MessageBegin,
	mm_MessageEnd,
	mm_WriteByte,
	mm_WriteChar,
	mm_WriteShort,
	mm_WriteLong,
	mm_WriteAngle,
	mm_WriteCoord,
	mm_WriteString,
	mm_WriteEntity,
	mm_CVarRegister,
	mm_CVarGetFloat,
	mm_CVarGetString,
	mm_CVarSetFloat,
	mm_CVarSetString,
	mm_AlertMessage,
	mm_EngineFprintf,
	mm_PvAllocEntPrivateData,
	mm_PvEntPrivateData,
	mm_FreeEntPrivateData,
	mm_SzFromIndex,
	mm_AllocString,
	mm_GetVarsOfEnt,
	mm_PEntityOfEntOffset,
	mm_EntOffsetOfPEntity,
	mm_IndexOfEdict,
	mm_PEntityOfEntIndex,
	mm_FindEntityByVars,
	mm_GetModelPtr,
	mm_RegUserMsg,
	mm_AnimationAutomove,
	mm_GetBonePosition,
	mm_FunctionFromName,
	mm_NameForFunction,
	mm_ClientPrintf,
	mm_ServerPrint,
	mm_Cmd_Args,
	mm_Cmd_Argv,
	mm_Cmd_Argc,
	mm_GetAttachment,
	mm_CRC32_Init,
	mm_CRC32_ProcessBuffer,
	mm_CRC32_ProcessByte,
	mm_CRC32_Final,
	mm_RandomLong,
	mm_RandomFloat,
	mm_SetView,
	mm_Time,
	mm_CrosshairAngle,
	mm_LoadFileForMe,
	mm_FreeFile,
	mm_EndSection,
	mm_CompareFileTime,
	mm_GetGameDir,
	mm_Cvar_RegisterVariable,
	mm_FadeClientVolume,
	mm_SetClientMaxspeed,
	mm_CreateFakeClient,
	mm_RunPlayerMove,
	mm_NumberOfEntities,
	mm_GetInfoKeyBuffer,
	mm_InfoKeyValue,
	mm_SetKeyValue,
	mm_SetClientKeyValue,
	mm_IsMapValid,
	mm_StaticDecal,
	mm_PrecacheGeneric,
	mm_GetPlayerUserId,
	mm_BuildSoundMsg,
	mm_IsDedicatedServer,
	mm_CVarGetPointer,
	mm_GetPlayerWONId,
	mm_Info_RemoveKey,
	mm_GetPhysicsKeyValue,
	mm_SetPhysicsKeyValue,
	mm_GetPhysicsInfoString,
	mm_PrecacheEvent,
	mm_PlaybackEvent,
	mm_SetFatPVS,
	mm_SetFatPAS,
	mm_CheckVisibility,
	mm_DeltaSetField,
	mm_DeltaUnsetField,
	mm_DeltaAddEncoder,
	mm_GetCurrentPlayer,
	mm_CanSkipPlayer,
	mm_DeltaFindField,
	mm_DeltaSetFieldByIndex,
	mm_DeltaUnsetFieldByIndex,
	mm_SetGroupMask,
	mm_CreateInstancedBaseline,
	mm_Cvar_DirectSet,
	mm_ForceUnmodified,
	mm_GetPlayerStats,
	mm_AddServerCommand,
	mm_Voice_GetClientListening,
	mm_Voice_SetClientListening,
	mm_GetPlayerAuthId,
	mm_SequenceGet,
	mm_SequencePickSentence,
	mm_GetFileSize,
	mm_GetApproxWavePlayLen,
	mm_IsCareerMatch,
	mm_GetLocalizedStringLength,
	mm_RegisterTutorMessageShown,
	mm_GetTimesTutorMessageShown,
	mm_ProcessTutorMessageDecayBuffer,
	mm_ConstructTutorMessageDecayBuffer,
	mm_ResetTutorMessageDecayData,
	mm_QueryClientCvarValue,
	mm_QueryClientCvarValue2,
	mm_EngCheckParm,
};

