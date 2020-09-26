import { MeasureUnit } from './MeasureUnit'
import { Md5 } from 'ts-md5/dist/md5'


export class Product {
  private id?: string;
  private name?: string;
  private price?: number;
  private measureUnit?: MeasureUnit

  constructor() { }

  public getId(): string | undefined {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getName(): string | undefined {
    return this.name;
  }

  public setName(name: string): void {
    this.name = name;
  }

  public getPrice(): number | undefined {
    return this.price;
  }

  public setPrice(price: number): void {
    this.price = price;
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


}