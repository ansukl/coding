const addToCart = productId => {
  // TODO 9.2
  // use addProductToCart(), available already from /public/js/utils.js
  // call updateProductAmount(productId) from this file
  addProductToCart(productId);
  updateProductAmount(productId);
};

const decreaseCount = productId => {
  // TODO 9.2
  // Decrease the amount of products in the cart, /public/js/utils.js provides decreaseProductCount()
  // Remove product from cart if amount is 0,  /public/js/utils.js provides removeElement = (containerId, elementId
  const count = decreaseProductCount(productId);
  if (!count) {
    removeElement("cart-container", productId);
  } else {
    updateProductAmount(productId);
  }
};

const updateProductAmount = productId => {
  // TODO 9.2
  // - read the amount of products in the cart, /public/js/utils.js provides getProductCountFromCart(productId)
  // - change the amount of products shown in the right element's innerText
  const count = getProductCountFromCart(productId);
  document.getElementById(`amount-${productId}`).innerText = `${count}x`;
};

const placeOrder = async() => {
  // TODO 9.2
  // Get all products from the cart, /public/js/utils.js provides getAllProductsFromCart()
  // show the user a notification: /public/js/utils.js provides createNotification = (message, containerId, isSuccess = true)
  // for each of the products in the cart remove them, /public/js/utils.js provides removeElement(containerId, elementId)
  const products = getAllProductsFromCart();
  products.forEach(product => {
    removeElement("cart-container", product.name)
  })

  clearCart();
  
  createNotification("Successfully created an order!", "notifications-container", true);
};

(async() => {
  // TODO 9.2
  // - get the 'cart-container' element
  // - use getJSON(url) to get the available products
  // - get all products from cart
  // - get the 'cart-item-template' template
  // - for each item in the cart
  //    * copy the item information to the template
  //    * hint: add the product's ID to the created element's as its ID to 
  //        enable editing ith 
  //    * remember to add event listeners for cart-minus-plus-button
  //        cart-minus-plus-button elements. querySelectorAll() can be used 
  //        to select all elements with each of those classes, then its 
  //        just up to finding the right index.  querySelectorAll() can be 
  //        used on the clone of "product in the cart" template to get its two
  //        elements with the "cart-minus-plus-button" class. Of the resulting
  //        element array, one item could be given the ID of 
  //        `plus-${product_id`, and other `minus-${product_id}`. At the same
  //        time we can attach the event listeners to these elements. Something 
  //        like the following will likely work:
  //          clone.querySelector('button').id = `add-to-cart-${prodouctId}`;
  //          clone.querySelector('button').addEventListener('click', () => addToCart(productId, productName));
  //
  // - in the end remember to append the modified cart item to the cart 
  const container = document.getElementById("cart-container");
  const template = document.getElementById("cart-item-template");

  const cartProducts = getAllProductsFromCart();
  const products = await getJSON("/api/products");

  cartProducts.forEach(cartProduct => {
    const product = products.find(item => item._id === cartProduct.name );

    const clone = template.content.cloneNode(true);

    clone.querySelector("div").id = product._id;

    clone.querySelector("h3").id = `name-${product._id}`;
    clone.querySelector("h3").textContent = product.name;

    clone.querySelector("p.product-price").id = `price-${product._id}`;
    clone.querySelector("p.product-price").textContent = product.price;

    clone.querySelector("p.product-amount").id = `amount-${product._id}`;
    clone.querySelector("p.product-amount").textContent = cartProduct.amount === "0" ? "0" : `${cartProduct.amount}x`;

    const buttons = clone.querySelectorAll("button.cart-minus-plus-button");

    buttons[0].id = `plus-${product._id}`;
    buttons[0].onclick = function () {
      addToCart(product._id);
    }

    buttons[1].id = `minus-${product._id}`;
    buttons[1].onclick = function () {
      decreaseCount(product._id);
    }

    container.appendChild(clone);
  });

  const submitOrderButton = document.getElementById("place-order-button");
  submitOrderButton.onclick = function () {
    placeOrder();
  }
})();