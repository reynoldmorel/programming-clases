import { Stock } from './Stock'
import { Product } from './Product'
import { MeasureUnit } from './MeasureUnit'


import { Md5 } from 'ts-md5/dist/md5'

export class StockProduct {
  private id: string;
  private stock: Stock;
  private product: Product
  private quantity: number;
  private measureUnit: MeasureUnit

  constructor() { }


  public getId(): string {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getStock(): Stock {
    return this.stock;
  }

  public setStock(stock: Stock): void {
    this.stock = stock;
  }

  public getProduct(): Product {
    return this.product;
  }

  public setProduct(product: Product): void {
    this.product = product;
  }

  public getQuantity(): number {
    return this.quantity;
  }

  public setQuantity(quantity: number): void {
    this.quantity = quantity;
  }

  public getMeasureUnit(): MeasureUnit {
    return this.measureUnit;
  }

  public setMeasureUnit(measureUnit: MeasureUnit): void {
    this.measureUnit = measureUnit;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }


}