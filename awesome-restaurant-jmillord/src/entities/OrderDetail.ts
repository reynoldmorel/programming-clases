import { Order } from './Order'
import { Product } from './Product'


export class OrderDetails {

  private _id?: string;
  private _order?: Order;
  private _product?: Product
  private _price?: number;
  private _quantity?: number

  constructor() { }

  get id(): string | undefined {
    return this._id
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get order(): Order | undefined {
    return this._order
  }

  set order(value: Order | undefined) {
    this._order = value
  }

  get product(): Product | undefined {
    return this._product
  }

  set product(value: Product | undefined) {
    this._product = value
  }

  get price(): number | undefined {
    return this._price
  }

  set price(value: number | undefined) {
    this._price = value
  }

  get quantity(): number | undefined {
    return this._quantity
  }

  set quantity(value: number | undefined) {
    this._quantity = value
  }



}