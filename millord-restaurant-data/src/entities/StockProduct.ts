import { Stock } from './Stock'
import { Product } from './Product'
import { MeasureUnit } from './MeasureUnit'


import { Md5 } from 'ts-md5/dist/md5'

export class StockProduct {
<<<<<<< HEAD
  private _id?: string;
  private _stock?: Stock;
  private _product?: Product
  private _quantity?: number;
  private _measureUnit?: MeasureUnit

  constructor() { }

  get id(): string | undefined {
    return this._id
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get stock(): Stock | undefined {
    return this._stock
  }

  get product(): Product | undefined {
    return this._product

  }
  set product(value: Product | undefined) {
    this._product = value
  }

  get quantity(): number | undefined {
    return this._quantity
  }

  set quantity(value: number | undefined) {
    this._quantity
  }

  get measureUnit(): MeasureUnit | undefined {
    return this._measureUnit
  }

  set measureUnit(value: MeasureUnit | undefined) {
    this._measureUnit = value
  }

=======
  private id?: string;
  private stock?: Stock;
  private product?: Product
  private quantity?: number;
  private measureUnit?: MeasureUnit

  constructor() { }


  public getId(): string | undefined {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getStock(): Stock | undefined {
    return this.stock;
  }

  public setStock(stock: Stock): void {
    this.stock = stock;
  }

  public getProduct(): Product | undefined {
    return this.product;
  }

  public setProduct(product: Product): void {
    this.product = product;
  }

  public getQuantity(): number | undefined {
    return this.quantity;
  }

  public setQuantity(quantity: number): void {
    this.quantity = quantity;
  }

  public getMeasureUnit(): MeasureUnit | undefined {
    return this.measureUnit;
  }

  public setMeasureUnit(measureUnit: MeasureUnit): void {
    this.measureUnit = measureUnit;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }


>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
}