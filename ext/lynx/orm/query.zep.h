
extern zend_class_entry *lynx_orm_query_ce;

ZEPHIR_INIT_CLASS(Lynx_ORM_Query);

PHP_METHOD(Lynx_ORM_Query, getQuery);
PHP_METHOD(Lynx_ORM_Query, getIdentityMap);
PHP_METHOD(Lynx_ORM_Query, setIdentityMap);
PHP_METHOD(Lynx_ORM_Query, __construct);
PHP_METHOD(Lynx_ORM_Query, bindValue);
PHP_METHOD(Lynx_ORM_Query, bindParam);
PHP_METHOD(Lynx_ORM_Query, getResult);
PHP_METHOD(Lynx_ORM_Query, fetchArray);
PHP_METHOD(Lynx_ORM_Query, fetchAll);
PHP_METHOD(Lynx_ORM_Query, fetchObject);
PHP_METHOD(Lynx_ORM_Query, fetchOne);
PHP_METHOD(Lynx_ORM_Query, execute);
PHP_METHOD(Lynx_ORM_Query, getScalarResult);

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_setidentitymap, 0, 0, 1)
	ZEND_ARG_INFO(0, identityMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_OBJ_INFO(0, em, Lynx\\ORM\\EntityManager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_bindvalue, 0, 0, 2)
	ZEND_ARG_INFO(0, parameter)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, data_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_bindparam, 0, 0, 2)
	ZEND_ARG_INFO(0, parameter)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, data_type)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, driver_options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_fetcharray, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_fetchall, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_fetchobject, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_fetchone, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, hydrationMod)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_lynx_orm_query_getscalarresult, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(lynx_orm_query_method_entry) {
	PHP_ME(Lynx_ORM_Query, getQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, getIdentityMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, setIdentityMap, arginfo_lynx_orm_query_setidentitymap, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, __construct, arginfo_lynx_orm_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Lynx_ORM_Query, bindValue, arginfo_lynx_orm_query_bindvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, bindParam, arginfo_lynx_orm_query_bindparam, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, getResult, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, fetchArray, arginfo_lynx_orm_query_fetcharray, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, fetchAll, arginfo_lynx_orm_query_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, fetchObject, arginfo_lynx_orm_query_fetchobject, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, fetchOne, arginfo_lynx_orm_query_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, execute, arginfo_lynx_orm_query_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Lynx_ORM_Query, getScalarResult, arginfo_lynx_orm_query_getscalarresult, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
