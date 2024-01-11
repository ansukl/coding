const decr = document.getElementById("decrement");
const incr = document.getElementById("increment");
const reset = document.getElementById("reset");
const count = document.getElementById("counter");

reset.addEventListener("click", function(event) {
    count.innerHTML = "0";
  });
decr.addEventListener("click", function(event) {   
    var num = Number.parseInt(count.innerHTML);
    var newcount = 0;
    if (num == -5) {
        newcount = 5;
    } else {
        newcount = num - 1;
    }
    newcount.toString();
    count.innerHTML = newcount;
  });
incr.addEventListener("click", function(event) {
    var num = Number.parseInt(count.innerHTML);
    var newcount = 0;
    if (num == 5) {
        newcount = -5;
    } else {
        newcount = num + 1;
    }
    newcount.toString();
    count.innerHTML = newcount;
  });