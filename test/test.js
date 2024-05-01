import utils from 'utils';

const a = 1;

// This is warning
let b = a + "1";

const err_01 = ; // missing value

const err_02 = (here_is_a_info) => {
  let var_1 = 1; // not used var
};


/**
 * @deprecated bla stuff pf
 */
const warning_method = () => {
  let hint = 1;
}

warning_method();
