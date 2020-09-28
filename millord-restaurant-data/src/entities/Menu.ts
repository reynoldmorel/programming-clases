import { FinalProduct } from './FinalProduct'
import { MenuItem } from './MenuItem'

import { Md5 } from 'ts-md5/dist/md5'


export class Menu {
<<<<<<< HEAD
  private _id?: string;
  private _name?: string;
  private _finalProducts?: Array<MenuItem>

  constructor() { }

  get id(): string | undefined {
    return this._id;
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get name(): string | undefined {
    return this._name;
  }

  set name(value: string | undefined) {
    this._name = value;
  }

  get finalProducts(): Array<MenuItem> | undefined {
    return this._finalProducts
  }

  set finalProducts(value: Array<MenuItem> | undefined) {
    this._finalProducts = value
  }

=======
  private id?: string;
  private name?: string;
  private finalProducts?: Array<MenuItem>

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

  public getFinalProducts(): Array<MenuItem> | undefined {
    return this.finalProducts;
  }

  public setFinalProducts(finalProducts: Array<MenuItem>): void {
    this.finalProducts = finalProducts;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }


>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b

}