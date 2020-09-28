import { Md5 } from 'ts-md5/dist/md5'



export class MeasureUnit {
<<<<<<< HEAD
  private _id?: string;
  private _name?: string;
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
=======
  private id?: string;
  private name?: string;
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
  public hashCode() {
    return Md5.hashStr(this.id)
  }

>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b


}