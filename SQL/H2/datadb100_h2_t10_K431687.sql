-- Database basics 2021
-- H2 T10
-- anna.kleemola@tuni.fi

PRAGMA foreign_keys = ON;

CREATE TABLE tea_shop (
    tea_shop_id INT,
    tea_shop_name VARCHAR(30) NOT NULL,
    shop_address VARCHAR(50),
    PRIMARY KEY (tea_shop_id),
    UNIQUE (tea_shop_name)
);

INSERT INTO tea_shop
VALUES (1, 'Teekauppa', 'Hämeenkatu 1');  

INSERT INTO tea_shop
VALUES (2, 'Teemaa', 'Hämeenkatu 2');

INSERT INTO tea_shop
VALUES (3, 'Teehuone', 'Hämeenkatu 3');


CREATE TABLE sells (
     tea_shop_id INT NOT NULL,
     id INT NOT NULL,
    PRIMARY KEY (tea_shop_id, id),
    FOREIGN KEY (tea_shop_id) REFERENCES tea_shop,
    FOREIGN KEY (id) REFERENCES tea
);

INSERT INTO sells
VALUES (1, 1);

INSERT INTO sells
VALUES (1, 4);

INSERT INTO sells
VALUES (1, 6);

INSERT INTO sells
VALUES (2, 1);

INSERT INTO sells
VALUES (2, 2);

INSERT INTO sells
VALUES (3, 2);

INSERT INTO sells
VALUES (1, 5);
