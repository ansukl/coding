-- T2
-- Kleemola Anna, K431687

CREATE TABLE keyword (
    keyword_id INT,
    word VARCHAR(30) NOT NULL,
    PRIMARY KEY (keyword_id),
    UNIQUE (word)
);

CREATE TABLE relates_to (
    k_id INT,
    w_id INT,
    PRIMARY KEY (k_id, w_id)
    FOREIGN KEY (k_id) REFERENCES keyword,
    FOREIGN KEY (w_id) REFERENCES wine
);
