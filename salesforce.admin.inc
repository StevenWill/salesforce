<?php
/**
 * @file
 * Admin form for the Salesforce module.
 *
 */

/**
 * Salesforce admin form to setup account and objects.
 *
 * @return type 
 */
function salesforce_admin_form() {
  $form = array();
  $form['salesforce_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#description' => t('Enter the client id provided by salesforce'),
    '#default_value' => variable_get('salesforce_client_id', ''),
  );
  $form['salesforce_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#description' => t('Enter the client secret provided by salesforce'),
    '#default_value' => variable_get('salesforce_client_secret', ''),
  );
  $form['salesforce_security_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Security Token'),
    '#default_value' => variable_get('salesforce_security_token', ''),
    '#description' => t('Enter to security token Salesforce emailed you. Do not inlude your password with the token'),
  );
  $form['salesforce_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('salesforce_username',''),
  );
  $form['salesforce_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('salesforce_password', ''),
  );
  $form['salesforce_login_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('Login URI'),
    '#default_value' => variable_get('salesforce_login_uri', ''),
  );
  $form['salesforce_objects'] = array(
    '#type' => 'textfield',
    '#title' => t('Objects'),
    '#description' => t('Add Salesforce objects to be available for import (Ex: Account, Contact, Campaign, Lead, Opporunity). '),
    '#default_value' => variable_get('salesforce_objects', ''),
  );
  return system_settings_form($form);
}

/**
 * Salesforce Import form.
 *
 * @param type $form
 * @param type $form_state
 * @return array 
 */
function salesforce_import($form, $form_state) {
  $form = array();
  $objects = explode(",", variable_get('salesforce_objects', ''));
  $options = array();
  foreach($objects as $value) {
    $options[trim($value)] = trim($value); 
  }

  $form['object'] = array(
    '#type' => 'select',
    '#title' => t('Object to Import'),
    '#options' => $options,
    '#description' => t('Select the Salesforce Object to import.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
    '#submit' => array('salesforce_batch'),
  );
  return $form;
}
