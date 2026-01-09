type ToBeOrNotToBe = {
  toBe: (val: any) => boolean;
  notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
  return {
    toBe(other: any): boolean {
      if (val === other) return true;
      throw new Error("Not Equal");
    },
    notToBe(other: any): boolean {
      if (val !== other) return true;
      throw new Error("Equal");
    }
  };
}
