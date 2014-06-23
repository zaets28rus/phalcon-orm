
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_Connection) {

	ZEPHIR_REGISTER_CLASS(Lynx\\DBAL, Connection, lynx, dbal_connection, lynx_dbal_connection_method_entry, 0);

	/**
	 * Current used driver
	 */
	zend_declare_property_null(lynx_dbal_connection_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Current used driver
 */
PHP_METHOD(Lynx_DBAL_Connection, getDriver) {


	RETURN_MEMBER(this_ptr, "driver");

}

PHP_METHOD(Lynx_DBAL_Connection, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *parameters, *eventsManager = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters, &eventsManager);

	if (!eventsManager) {
		ZEPHIR_CPY_WRT(eventsManager, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(eventsManager);
	}


	_0 = Z_TYPE_P(eventsManager) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(eventsManager, lynx_stdlib_events_manager_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Lynx\\Stdlib\\Events\\Manager'", "", 0);
		return;
	}
	if (Z_TYPE_P(eventsManager) == IS_NULL) {
		ZEPHIR_INIT_NVAR(eventsManager);
		object_init_ex(eventsManager, lynx_stdlib_events_manager_ce);
		if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	if (zephir_array_isset_string(parameters, SS("driver"))) {
		zephir_array_fetch_string(&_1, parameters, SL("driver"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("driver"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Driver didn`t find in $parameters", "lynx/DBAL/Connection.zep", 28);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "seteventsmanager", NULL, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Insert row to the table with spicifed data and types
 * return the nubmer of affected rows
 */
PHP_METHOD(Lynx_DBAL_Connection, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *types = NULL;
	zval *table_param = NULL, *data_param = NULL, *types_param = NULL, *query, *_0, *_1, *_2, *_3;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &types_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(table_param) == IS_STRING)) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;

	if (!types_param) {
		ZEPHIR_INIT_VAR(types);
		array_init(types);
	} else {
	if (unlikely(Z_TYPE_P(types_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'types' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		types = types_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_array_keys(_1, data TSRMLS_CC);
	zephir_fast_join_str(_0, SL(", "), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_join_str(_2, SL(", "), data TSRMLS_CC);
	ZEPHIR_INIT_VAR(query);
	ZEPHIR_CONCAT_SVSVSSVS(query, "INSERT INTO ", table, " (", _0, ")", " VALUES (", _2, ")");
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_3, "execute", NULL, query);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_DBAL_Connection, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement, *smt = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&smt, _0, "prepare", NULL, statement);
	zephir_check_call_status();
	RETURN_CCTOR(smt);

}

