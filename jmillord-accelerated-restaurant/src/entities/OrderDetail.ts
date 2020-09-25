import { Order } from './Order'
import { Product } from './Product'
import { Md5 } from 'ts-md5/dist/md5'

export class OrderDetails {
  private id: string;
  private order: Order;
  private product: Product
  private price: number;
  private quantity: number

  constructor() { }

  public getId(): string {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getOrder(): Order {
    return this.order;
  }

  public setOrder(order: Order): void {
    this.order = order;
  }

  public getProduct(): Product {
    return this.product;
  }

  public setProduct(product: Product): void {
    this.product = product;
  }

  public getPrice(): number {
    return this.price;
  }

  public setPrice(price: number): void {
    this.price = price;
  }

  public getQuantity(): number {
    return this.quantity;
  }

  public setQuantity(quantity: number): void {
    this.quantity = quantity;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }

}