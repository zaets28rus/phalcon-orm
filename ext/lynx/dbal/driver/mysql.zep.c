
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_MySQL) {

	ZEPHIR_REGISTER_CLASS(Lynx\\DBAL\\Driver, MySQL, lynx, dbal_driver_mysql, lynx_dbal_driver_mysql_method_entry, 0);

	zend_declare_property_null(lynx_dbal_driver_mysql_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_dbal_driver_mysql_ce, SL("dsn"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_dbal_driver_mysql_ce, SL("username"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_dbal_driver_mysql_ce, SL("password"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_dbal_driver_mysql_ce, SL("driverOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_dbal_driver_mysql_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("eventsManager"), eventsManager TSRMLS_CC);

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, getEventsManager) {


	RETURN_MEMBER(this_ptr, "eventsManager");

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, __construct) {

	zval *driverOptions = NULL;
	zval *dsn_param = NULL, *username = NULL, *password = NULL, *driverOptions_param = NULL;
	zval *dsn = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn_param, &username, &password, &driverOptions_param);

	if (unlikely(Z_TYPE_P(dsn_param) != IS_STRING && Z_TYPE_P(dsn_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dsn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(dsn_param) == IS_STRING)) {
		zephir_get_strval(dsn, dsn_param);
	} else {
		ZEPHIR_INIT_VAR(dsn);
		ZVAL_EMPTY_STRING(dsn);
	}
	if (!username) {
		username = ZEPHIR_GLOBAL(global_null);
	}
	if (!password) {
		password = ZEPHIR_GLOBAL(global_null);
	}
	if (!driverOptions_param) {
		ZEPHIR_INIT_VAR(driverOptions);
		array_init(driverOptions);
	} else {
		zephir_get_arrval(driverOptions, driverOptions_param);
	}


	zephir_update_property_this(this_ptr, SL("dsn"), dsn TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("username"), username TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("password"), password TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("driverOptions"), driverOptions TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, isConnected) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	RETURN_BOOL(!(Z_TYPE_P(_0) == IS_NULL));

}

/**
 * Execute query and return result
 */
PHP_METHOD(Lynx_DBAL_Driver_MySQL, execute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, *_0;
	zval *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	if (unlikely(Z_TYPE_P(query_param) != IS_STRING && Z_TYPE_P(query_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'query' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(query_param) == IS_STRING)) {
		zephir_get_strval(query, query_param);
	} else {
		ZEPHIR_INIT_VAR(query);
		ZVAL_EMPTY_STRING(query);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "exec", NULL, query);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, connect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isconnected", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, lynx_dbal_driver_pdo_ce);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("dsn"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("username"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("password"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("driverOptions"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, _4, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("connection"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, getNewPlatform) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, lynx_dbal_platform_mysql_ce);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, lastInsertId) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "lastinsertid", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Lynx_DBAL_Driver_MySQL, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "prepare", NULL, statement);
	zephir_check_call_status();
	RETURN_MM();

}

