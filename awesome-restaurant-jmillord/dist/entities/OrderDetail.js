"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.OrderDetails = void 0;
var OrderDetails = /** @class */ (function () {
    function OrderDetails() {
    }
    Object.defineProperty(OrderDetails.prototype, "id", {
        get: function () {
            return this._id;
        },
        set: function (value) {
            this._id = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(OrderDetails.prototype, "order", {
        get: function () {
            return this._order;
        },
        set: function (value) {
            this._order = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(OrderDetails.prototype, "product", {
        get: function () {
            return this._product;
        },
        set: function (value) {
            this._product = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(OrderDetails.prototype, "price", {
        get: function () {
            return this._price;
        },
        set: function (value) {
            this._price = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(OrderDetails.prototype, "quantity", {
        get: function () {
            return this._quantity;
        },
        set: function (value) {
            this._quantity = value;
        },
        enumerable: false,
        configurable: true
    });
    return OrderDetails;
}());
exports.OrderDetails = OrderDetails;
