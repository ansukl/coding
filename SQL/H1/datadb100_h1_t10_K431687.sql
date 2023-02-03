-- Database basics 2021
-- H1 T10
-- anna.kleemola@tuni.fi

CREATE TABLE shoe (
    id          INT NOT NULL,
    name        VARCHAR(25) NOT NULL,
    type        VARCHAR(25),
    price       DECIMAL(5,2),
    PRIMARY KEY (id),
    UNIQUE (name)
);

INSERT INTO shoe
VALUES (1, 'X 10', 'sprint', 79.95);  

INSERT INTO shoe
VALUES (4, 'ABC 101', 'sprint', 124.95);  

INSERT INTO shoe
VALUES (6, 'ABC 201', 'long jump', 159.00);

INSERT INTO shoe
VALUES (7, 'X 20', 'middle-distance', NULL);  
