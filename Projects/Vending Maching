// SPDX-License-Identifier: MIT
<*keyword*> solidity 0.8.7;

contract VendingMachine {

    // Declaring state variables of the contract
    address <*access specifier*> owner;
    mapping (address => uint) public cupcakeBalances;

    // When 'VendingMachine' contract is deployed:
    // 1. set the deploying address as the owner of the contract
    // 2. set the deployed smart contract's cupcake balance 
    constructor() {
        <*____*> = msg.sender;
        cupcakeBalances[address(owner)] = <*enter balance*>;
    }

    // Allow the owner to increase the smart contract's cupcake balance
    function refill(uint amount) public {
        require(msg.sender == owner, "Only the owner can refill.");
        cupcakeBalances[owner] += amount;
    }

    // Allow anyone to purchase cupcakes
    <*keyword*> purchase(uint amount) public payable {
        require(msg.value >= amount * 1 ether, "You must pay at least 1 ETH per cupcake");
        require(cupcakeBalances[address(owner)] >= amount, "Not enough cupcakes in stock to complete this purchase");
        cupcakeBalances[address(owner)] -= amount;
        cupcakeBalances[owner] += amount;
    }
}
