CREATE DATABASE template0 IS_TEMPLATE = true ALLOW_CONNECTIONS = false;


UPDATE pg_database SET datlastsysoid = (SELECT oid FROM pg_database WHERE datname = 'template0');


REVOKE CREATE,TEMPORARY ON DATABASE template1 FROM public;


REVOKE CREATE,TEMPORARY ON DATABASE template0 FROM public;


COMMENT ON DATABASE template0 IS 'unmodifiable empty database';


VACUUM pg_database;


