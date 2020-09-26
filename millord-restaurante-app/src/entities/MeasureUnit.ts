import { Md5 } from 'ts-md5/dist/md5'



export class MeasureUnit {
  private id: string;
  private name: string;
  constructor() { }

  public getId(): string {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getName(): string {
    return this.name;
  }

  public setName(name: string): void {
    this.name = name;
  }
  public hashCode() {
    return Md5.hashStr(this.id)
  }



}