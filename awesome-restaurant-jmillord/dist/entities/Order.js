"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Order = void 0;
var Order = /** @class */ (function () {
    function Order() {
    }
    Object.defineProperty(Order.prototype, "id", {
        get: function () {
            return this._id;
        },
        set: function (value) {
            this._id = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Order.prototype, "transactionDate", {
        get: function () {
            return this._transactionDate;
        },
        set: function (value) {
            this._transactionDate = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Order.prototype, "client", {
        get: function () {
            return this._client;
        },
        set: function (value) {
            this._client = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Order.prototype, "cashier", {
        get: function () {
            return this._cashier;
        },
        set: function (value) {
            this._cashier = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Order.prototype, "orderDetails", {
        get: function () {
            return this._orderDetails;
        },
        set: function (value) {
            this._orderDetails = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Order.prototype, "totalAmount", {
        get: function () {
            return this._totalAmount;
        },
        set: function (value) {
            this._totalAmount = value;
        },
        enumerable: false,
        configurable: true
    });
    return Order;
}());
exports.Order = Order;
