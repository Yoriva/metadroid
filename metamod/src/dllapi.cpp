#include "precompiled.h"

extern DLL_FUNCTIONS sFunctionTable;
DLL_FUNCTIONS *pHookedDllFunctions = &sFunctionTable;
extern NEW_DLL_FUNCTIONS sNewFunctionTable;
NEW_DLL_FUNCTIONS *pHookedNewDllFunctions = &sNewFunctionTable;

static void mm_GameInit(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnGameInit;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnGameInit;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGameInit;
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

static int mm_Spawn(edict_t *pent)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpawn;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSpawn;
		if (_fn) {
			dllret = _fn(pent);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpawn;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pent);
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

static void mm_Think(edict_t *pent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnThink;
		if (_fn) {
			_fn(pent);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_Use(edict_t *pentUsed, edict_t *pentOther)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnUse;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentUsed, pentOther);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnUse;
		if (_fn) {
			_fn(pentUsed, pentOther);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnUse;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentUsed, pentOther);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_Touch(edict_t *pentTouched, edict_t *pentOther)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnTouch;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentTouched, pentOther);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnTouch;
		if (_fn) {
			_fn(pentTouched, pentOther);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnTouch;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentTouched, pentOther);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_Blocked(edict_t *pentBlocked, edict_t *pentOther)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnBlocked;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentBlocked, pentOther);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnBlocked;
		if (_fn) {
			_fn(pentBlocked, pentOther);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnBlocked;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentBlocked, pentOther);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_KeyValue(edict_t *pentKeyvalue, KeyValueData *pkvd)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentKeyvalue, pkvd);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnKeyValue;
		if (_fn) {
			_fn(pentKeyvalue, pkvd);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnKeyValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pentKeyvalue, pkvd);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_Save(edict_t *pent, SAVERESTOREDATA *pSaveData)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSave;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent, pSaveData);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSave;
		if (_fn) {
			_fn(pent, pSaveData);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSave;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent, pSaveData);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_Restore(edict_t *pent, SAVERESTOREDATA *pSaveData, int globalEntity)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnRestore;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pent, pSaveData, globalEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnRestore;
		if (_fn) {
			dllret = _fn(pent, pSaveData, globalEntity);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRestore;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pent, pSaveData, globalEntity);
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

static void mm_SetAbsBox(edict_t *pent)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetAbsBox;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSetAbsBox;
		if (_fn) {
			_fn(pent);
		}
		else {
			pent->v.absmin[0] = pent->v.origin[0] + pent->v.mins[0];
			pent->v.absmin[1] = pent->v.origin[1] + pent->v.mins[1];
			pent->v.absmin[2] = pent->v.origin[2] + pent->v.mins[2];
			pent->v.absmax[0] = pent->v.origin[0] + pent->v.maxs[0];
			pent->v.absmax[1] = pent->v.origin[1] + pent->v.maxs[1];
			pent->v.absmax[2] = pent->v.origin[2] + pent->v.maxs[2];
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetAbsBox;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pent);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SaveWriteFields(SAVERESTOREDATA *pSaveData, const char *pname, void *pBaseData, TYPEDESCRIPTION *pFields, int fieldCount)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveWriteFields;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData, pname, pBaseData, pFields, fieldCount);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSaveWriteFields;
		if (_fn) {
			_fn(pSaveData, pname, pBaseData, pFields, fieldCount);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveWriteFields;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData, pname, pBaseData, pFields, fieldCount);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SaveReadFields(SAVERESTOREDATA *pSaveData, const char *pname, void *pBaseData, TYPEDESCRIPTION *pFields, int fieldCount)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveReadFields;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData, pname, pBaseData, pFields, fieldCount);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSaveReadFields;
		if (_fn) {
			_fn(pSaveData, pname, pBaseData, pFields, fieldCount);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveReadFields;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData, pname, pBaseData, pFields, fieldCount);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SaveGlobalState(SAVERESTOREDATA *pSaveData)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveGlobalState;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSaveGlobalState;
		if (_fn) {
			_fn(pSaveData);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSaveGlobalState;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_RestoreGlobalState(SAVERESTOREDATA *pSaveData)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnRestoreGlobalState;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnRestoreGlobalState;
		if (_fn) {
			_fn(pSaveData);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRestoreGlobalState;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pSaveData);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ResetGlobalState(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnResetGlobalState;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnResetGlobalState;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnResetGlobalState;
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

static void mm_ClientKill(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientKill;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnClientKill;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientKill;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ClientPutInServer(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientPutInServer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnClientPutInServer;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientPutInServer;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ClientUserInfoChanged(edict_t *pEntity, char *infobuffer)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientUserInfoChanged;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity, infobuffer);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnClientUserInfoChanged;
		if (_fn) {
			_fn(pEntity, infobuffer);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientUserInfoChanged;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity, infobuffer);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ServerActivate(edict_t *pEdictList, int edictCount, int clientMax)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerActivate;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdictList, edictCount, clientMax);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnServerActivate;
		if (_fn) {
			_fn(pEdictList, edictCount, clientMax);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerActivate;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEdictList, edictCount, clientMax);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_PlayerPreThink(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlayerPreThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnPlayerPreThink;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlayerPreThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_PlayerPostThink(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlayerPostThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnPlayerPostThink;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlayerPostThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_StartFrame(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnStartFrame;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnStartFrame;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnStartFrame;
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

static void mm_ParmsNewLevel(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnParmsNewLevel;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnParmsNewLevel;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnParmsNewLevel;
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

static void mm_ParmsChangeLevel(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnParmsChangeLevel;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnParmsChangeLevel;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnParmsChangeLevel;
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

static const char * mm_GetGameDescription(void)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetGameDescription;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnGetGameDescription;
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
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetGameDescription;
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

static void mm_PlayerCustomization(edict_t *pEntity, customization_t *pCustom)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlayerCustomization;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity, pCustom);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnPlayerCustomization;
		if (_fn) {
			_fn(pEntity, pCustom);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPlayerCustomization;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity, pCustom);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SpectatorConnect(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpectatorConnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSpectatorConnect;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpectatorConnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SpectatorDisconnect(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpectatorDisconnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSpectatorDisconnect;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpectatorDisconnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_SpectatorThink(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpectatorThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSpectatorThink;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSpectatorThink;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_Sys_Error(const char *error_string)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSys_Error;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(error_string);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSys_Error;
		if (_fn) {
			_fn(error_string);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSys_Error;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(error_string);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_PM_Move(struct playermove_s *ppmove, qboolean server)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnPM_Move;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ppmove, server);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnPM_Move;
		if (_fn) {
			_fn(ppmove, server);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPM_Move;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ppmove, server);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_PM_Init(struct playermove_s *ppmove)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnPM_Init;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ppmove);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnPM_Init;
		if (_fn) {
			_fn(ppmove);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPM_Init;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ppmove);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static char mm_PM_FindTextureType(char *name)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	char dllret{};
	char override_ret{};
	char pub_override_ret{};
	char orig_ret{};
	char pub_orig_ret{};
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnPM_FindTextureType;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnPM_FindTextureType;
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
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnPM_FindTextureType;
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

static void mm_SetupVisibility(struct edict_s *pViewEntity, struct edict_s *pClient, unsigned char **pvs, unsigned char **pas)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetupVisibility;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pViewEntity, pClient, pvs, pas);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnSetupVisibility;
		if (_fn) {
			_fn(pViewEntity, pClient, pvs, pas);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnSetupVisibility;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pViewEntity, pClient, pvs, pas);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_UpdateClientData(const struct edict_s *ent, int sendweapons, struct clientdata_s *cd)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnUpdateClientData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent, sendweapons, cd);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnUpdateClientData;
		if (_fn) {
			_fn(ent, sendweapons, cd);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnUpdateClientData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(ent, sendweapons, cd);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_AddToFullPack(struct entity_state_s *state, int e, edict_t *ent, edict_t *host, int hostflags, int player, unsigned char *pSet)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnAddToFullPack;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(state, e, ent, host, hostflags, player, pSet);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnAddToFullPack;
		if (_fn) {
			dllret = _fn(state, e, ent, host, hostflags, player, pSet);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnAddToFullPack;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(state, e, ent, host, hostflags, player, pSet);
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

static void mm_CreateBaseline(int player, int eindex, struct entity_state_s *baseline, struct edict_s *entity, int playermodelindex, vec3_t player_mins, vec3_t player_maxs)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateBaseline;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player, eindex, baseline, entity, playermodelindex, player_mins, player_maxs);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnCreateBaseline;
		if (_fn) {
			_fn(player, eindex, baseline, entity, playermodelindex, player_mins, player_maxs);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateBaseline;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player, eindex, baseline, entity, playermodelindex, player_mins, player_maxs);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_RegisterEncoders(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnRegisterEncoders;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnRegisterEncoders;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnRegisterEncoders;
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

static int mm_GetWeaponData(struct edict_s *player, struct weapon_data_s *info)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetWeaponData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(player, info);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnGetWeaponData;
		if (_fn) {
			dllret = _fn(player, info);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetWeaponData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(player, info);
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

static void mm_CmdStart(const edict_t *player, const struct usercmd_s *cmd, unsigned int random_seed)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmdStart;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player, cmd, random_seed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnCmdStart;
		if (_fn) {
			_fn(player, cmd, random_seed);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmdStart;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player, cmd, random_seed);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_CmdEnd(const edict_t *player)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmdEnd;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnCmdEnd;
		if (_fn) {
			_fn(player);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCmdEnd;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(player);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_ConnectionlessPacket(const struct netadr_s *net_from_, const char *args, char *response_buffer, int *response_buffer_size)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnConnectionlessPacket;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(net_from_, args, response_buffer, response_buffer_size);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnConnectionlessPacket;
		if (_fn) {
			dllret = _fn(net_from_, args, response_buffer, response_buffer_size);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnConnectionlessPacket;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(net_from_, args, response_buffer, response_buffer_size);
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

static int mm_GetHullBounds(int hullnumber, float *mins, float *maxs)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetHullBounds;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(hullnumber, mins, maxs);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnGetHullBounds;
		if (_fn) {
			dllret = _fn(hullnumber, mins, maxs);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGetHullBounds;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(hullnumber, mins, maxs);
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

static void mm_CreateInstancedBaselines(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateInstancedBaselines;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnCreateInstancedBaselines;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCreateInstancedBaselines;
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

static int mm_InconsistentFile(const struct edict_s *player, const char *filename, char *disconnect_message)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnInconsistentFile;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(player, filename, disconnect_message);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnInconsistentFile;
		if (_fn) {
			dllret = _fn(player, filename, disconnect_message);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnInconsistentFile;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(player, filename, disconnect_message);
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

static int mm_AllowLagCompensation(void)
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
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnAllowLagCompensation;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnAllowLagCompensation;
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
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnAllowLagCompensation;
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

static void mm_OnFreeEntPrivateData(edict_t *pEnt)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnOnFreeEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEnt);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.newapi_table) {
		auto _fn = g_GameDLL.funcs.newapi_table->pfnOnFreeEntPrivateData;
		if (_fn) {
			_fn(pEnt);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnOnFreeEntPrivateData;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEnt);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static int mm_ShouldCollide(edict_t *pentTouched, edict_t *pentOther)
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
		auto *_t = _p->m_newapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnShouldCollide;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pentTouched, pentOther);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.newapi_table) {
		auto _fn = g_GameDLL.funcs.newapi_table->pfnShouldCollide;
		if (_fn) {
			dllret = _fn(pentTouched, pentOther);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnShouldCollide;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pentTouched, pentOther);
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

static void mm_CvarValue2(const edict_t *pEnt, int requestID, const char *cvarName, const char *value)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvarValue2;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEnt, requestID, cvarName, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.newapi_table) {
		auto _fn = g_GameDLL.funcs.newapi_table->pfnCvarValue2;
		if (_fn) {
			_fn(pEnt, requestID, cvarName, value);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvarValue2;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEnt, requestID, cvarName, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static qboolean mm_ClientConnect(edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128])
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	qboolean dllret = 0, override_ret = 0, pub_override_ret = 0, orig_ret = 0, pub_orig_ret = 0;
	g_players.clear_player_cvar_query(pEntity);
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientConnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEntity, pszName, pszAddress, szRejectReason);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		if (mres == MRES_SUPERCEDE) override_ret = pub_override_ret = dllret;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnClientConnect;
		if (_fn) {
			dllret = _fn(pEntity, pszName, pszAddress, szRejectReason);
		}
	}
	orig_ret = dllret;
	pub_orig_ret = orig_ret;
	g_metaGlobals.orig_ret = &pub_orig_ret;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientConnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		pub_orig_ret = orig_ret;
		g_metaGlobals.orig_ret = &pub_orig_ret;
		pub_override_ret = override_ret;
		g_metaGlobals.override_ret = &pub_override_ret;
		dllret = _fn(pEntity, pszName, pszAddress, szRejectReason);
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

static void mm_ClientDisconnect(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	g_players.clear_player_cvar_query(pEntity);
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientDisconnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnClientDisconnect;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientDisconnect;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ClientCommand(edict_t *pEntity)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	if (g_config->m_clientmeta && !Q_strcmp(CMD_ARGV(0), "meta"))
		client_meta(pEntity);
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnClientCommand;
		if (_fn) {
			_fn(pEntity);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnClientCommand;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEntity);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_ServerDeactivate(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerDeactivate;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.dllapi_table) {
		auto _fn = g_GameDLL.funcs.dllapi_table->pfnServerDeactivate;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_dllapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnServerDeactivate;
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
	g_plugins->refresh(PT_CHANGELEVEL);
	g_plugins->unpause_all();
	g_players.clear_all_cvar_queries();
	g_requestid_counter = 0;
	g_metaGlobals = backup;
}

static void mm_CvarValue(const edict_t *pEnt, const char *value)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	g_players.clear_player_cvar_query(pEnt);
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvarValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEnt, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.newapi_table) {
		auto _fn = g_GameDLL.funcs.newapi_table->pfnCvarValue;
		if (_fn) {
			_fn(pEnt, value);
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnCvarValue;
		if (!_fn) continue;
		g_metaGlobals.mres = MRES_UNSET;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
		_fn(pEnt, value);
		mres = g_metaGlobals.mres;
		if ((int)mres > (int)status) status = mres;
		prev_mres = mres;
		g_metaGlobals.prev_mres = prev_mres;
		g_metaGlobals.status = status;
	}
	g_metaGlobals = backup;
}

static void mm_GameShutdown(void)
{
	meta_globals_t backup = g_metaGlobals;
	META_RES mres = MRES_UNSET, status = MRES_UNSET, prev_mres = MRES_UNSET;
	prev_mres = MRES_UNSET;
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_table;
		if (!_t) continue;
		auto _fn = _t->pfnGameShutdown;
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
	if (status != MRES_SUPERCEDE && g_GameDLL.funcs.newapi_table) {
		auto _fn = g_GameDLL.funcs.newapi_table->pfnGameShutdown;
		if (_fn) {
			_fn();
		}
	}
	if (g_plugins) for (auto *_p : *g_plugins->getPlugins()) {
		if (_p->status() != PL_RUNNING) continue;
		auto *_t = _p->m_newapi_post_table;
		if (!_t) continue;
		auto _fn = _t->pfnGameShutdown;
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
	g_metamod_active = false;
	if (g_plugins && !g_dedicated_server)
		g_plugins->unload_all();
	g_meta_extdll.unload();
	g_GameDLL.sys_module.unload();
	g_engine.sys_module.unload();
	g_metaGlobals = backup;
}

DLL_FUNCTIONS sFunctionTable =
{
	mm_GameInit,
	mm_Spawn,
	mm_Think,
	mm_Use,
	mm_Touch,
	mm_Blocked,
	mm_KeyValue,
	mm_Save,
	mm_Restore,
	mm_SetAbsBox,
	mm_SaveWriteFields,
	mm_SaveReadFields,
	mm_SaveGlobalState,
	mm_RestoreGlobalState,
	mm_ResetGlobalState,
	mm_ClientConnect,
	mm_ClientDisconnect,
	mm_ClientKill,
	mm_ClientPutInServer,
	mm_ClientCommand,
	mm_ClientUserInfoChanged,
	mm_ServerActivate,
	mm_ServerDeactivate,
	mm_PlayerPreThink,
	mm_PlayerPostThink,
	mm_StartFrame,
	mm_ParmsNewLevel,
	mm_ParmsChangeLevel,
	mm_GetGameDescription,
	mm_PlayerCustomization,
	mm_SpectatorConnect,
	mm_SpectatorDisconnect,
	mm_SpectatorThink,
	mm_Sys_Error,
	mm_PM_Move,
	mm_PM_Init,
	mm_PM_FindTextureType,
	mm_SetupVisibility,
	mm_UpdateClientData,
	mm_AddToFullPack,
	mm_CreateBaseline,
	mm_RegisterEncoders,
	mm_GetWeaponData,
	mm_CmdStart,
	mm_CmdEnd,
	mm_ConnectionlessPacket,
	mm_GetHullBounds,
	mm_CreateInstancedBaselines,
	mm_InconsistentFile,
	mm_AllowLagCompensation,
};

NEW_DLL_FUNCTIONS sNewFunctionTable =
{
	&mm_OnFreeEntPrivateData,
	&mm_GameShutdown,
	&mm_ShouldCollide,
	&mm_CvarValue,
	&mm_CvarValue2,
};

C_DLLEXPORT int GetEntityAPI(DLL_FUNCTIONS *pFunctionTable, int interfaceVersion)
{
	META_DEBUG(3, "called: GetEntityAPI; version=%d", interfaceVersion);
	if (!pFunctionTable) {
		META_ERROR("GetEntityAPI called with null pFunctionTable");
		return FALSE;
	}
	if (interfaceVersion != INTERFACE_VERSION) {
		META_ERROR("GetEntityAPI version mismatch; requested=%d ours=%d", interfaceVersion, INTERFACE_VERSION);
		return FALSE;
	}
	Q_memcpy(pFunctionTable, &sFunctionTable, sizeof(DLL_FUNCTIONS));
	return TRUE;
}

C_DLLEXPORT int GetEntityAPI2(DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion)
{
	META_DEBUG(3, "called: GetEntityAPI2; version=%d", *interfaceVersion);
	if (!pFunctionTable) {
		META_ERROR("GetEntityAPI2 called with null pFunctionTable");
		return FALSE;
	}
	if (*interfaceVersion != INTERFACE_VERSION) {
		META_ERROR("GetEntityAPI2 version mismatch; requested=%d ours=%d", *interfaceVersion, INTERFACE_VERSION);
		*interfaceVersion = INTERFACE_VERSION;
		return FALSE;
	}
	Q_memcpy(pFunctionTable, &sFunctionTable, sizeof(DLL_FUNCTIONS));
	return TRUE;
}

C_DLLEXPORT int GetNewDLLFunctions(NEW_DLL_FUNCTIONS *pNewFunctionTable, int *interfaceVersion)
{
	META_DEBUG(6, "called: GetNewDLLFunctions; version=%d", *interfaceVersion);
	if (!pNewFunctionTable) {
		META_ERROR("GetNewDLLFunctions called with null pNewFunctionTable");
		return FALSE;
	}
	if (*interfaceVersion != NEW_DLL_FUNCTIONS_VERSION) {
		META_ERROR("GetNewDLLFunctions version mismatch; requested=%d ours=%d", *interfaceVersion, NEW_DLL_FUNCTIONS_VERSION);
		*interfaceVersion = NEW_DLL_FUNCTIONS_VERSION;
		return FALSE;
	}
	g_meta_extdll.load();
	Q_memcpy(pNewFunctionTable, &sNewFunctionTable, sizeof(NEW_DLL_FUNCTIONS));
	return TRUE;
}

