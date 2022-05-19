-- CREATE TABLE [TABLE_NAME](
--     [COL_NAME1 TYPE][PRIMARY KEY][NOT NULL/NULL],
--     [COL_NAME2 TYPE2],
--     [COL_NAME1 TYPE3],
--     ...
-- )

CREATE TABLE helloStranger(
    id VARCHAR(10) NOT NULL,
    pwd VARCHAR(20) NOT NULL,
    name CHAR(6) NULL,
    mobile VARCHAR(20) NULL,
    email VARCHAR(20) NULL,
    address VARCHAR(50) NULL,
    num1 CHAR(6) NULL,
    num2 CHAR(8) NULL,
)
-- CHAR(4)
-- '' / '' / 4bytes
--'123' / '123' / 4bytes
--'12345' / '1234' / 4bytes

-- VARCHAR(4)
--" / 1bytes
--'123' / 4bytes
--'1234' / 5bytes