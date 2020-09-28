import { Order } from './Order'
import { Product } from './Product'
import { Md5 } from 'ts-md5/dist/md5'

export class OrderDetails {
<<<<<<< HEAD
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

=======
  private id?: string;
  private order?: Order;
  private product?: Product
  private price?: number;
  private quantity?: number

  constructor() { }

  public getId(): string | undefined {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getOrder(): Order | undefined {
    return this.order;
  }

  public setOrder(order: Order): void {
    this.order = order;
  }

  public getProduct(): Product | undefined {
    return this.product;
  }

  public setProduct(product: Product): void {
    this.product = product;
  }

  public getPrice(): number | undefined {
    return this.price;
  }

  public setPrice(price: number): void {
    this.price = price;
  }

  public getQuantity(): number | undefined {
    return this.quantity;
  }

  public setQuantity(quantity: number): void {
    this.quantity = quantity;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }
>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b

}