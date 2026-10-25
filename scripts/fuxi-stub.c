/*
 * Weak stubs for native symbols that UniXNU's XNU patches reference even when the
 * matching feature is switched off in the defconfig.
 *
 * Why this exists: patches/xnu add calls such as
 *   extern void native_legacy_display_probe(void); native_legacy_display_probe();
 * inside "#if DEVELOPMENT || DEBUG" blocks without also testing the feature macro,
 * so bsd_init.o references the symbol no matter what CONFIG_XNU_* says. The sheng
 * build always ships the archives that define them, so upstream never noticed.
 *
 * fuxi's bring-up build leaves those features off (no display archive, no
 * owner-trust chain, no boot progress), and they are unreachable anyway: each is
 * behind a boot argument that the fuxi payload does not pass. Defining them weak
 * keeps the link happy and lets a real archive override them later.
 */

#define FUXI_WEAK __attribute__((weak))

/* Display */
FUXI_WEAK void native_legacy_display_probe(void) {}
FUXI_WEAK void native_legacy_display_late_probe(void) {}

/* Boot progress */
FUXI_WEAK void boot_progress_poll(void) {}

/* Owner-root verified-root chain */
FUXI_WEAK const unsigned char verified_root_key[128] = { 0 };
FUXI_WEAK const unsigned char verified_root_policies[4096] = { 0 };
FUXI_WEAK const int verified_root_policy_count = 0;

FUXI_WEAK int vr_open(void) { return 0; }
FUXI_WEAK int vr_verify_block(void) { return 0; }
FUXI_WEAK int vr_xnu_crypto(void) { return 0; }

/* mockfs, in case the mockfs sources are not compiled into vfs_conf.o */
FUXI_WEAK int mockfs_mountroot(void) { return 0; }
FUXI_WEAK const unsigned char mockfs_vfsops[512] = { 0 };
FUXI_WEAK const unsigned char mockfs_vnodeop_opv_desc[512] = { 0 };

/* DriverKit user-server RPC (iokit/Kernel/IOUserServer.cpp, "optional iokitcpp").
 * The prelink needs a native address for it because an original kext references it,
 * and this kernel build has no iokitcpp objects. Nothing on the bring-up path drives
 * a DriverKit user server, so a NULL-returning stub only has to satisfy the rebind.
 */
FUXI_WEAK void *IORPCMessageFromMach(void *message, int reply)
{
	(void)message; (void)reply;
	return 0;
}

/* --- boot progress weak imports (generated) --------------------------------- */
/* BootProgress.c weak-imports its counters and row buffers; the kernel link wants
 * definitions. Zeroed weak definitions are enough: the layer only displays them. */
FUXI_WEAK unsigned long boot_log_tick;
FUXI_WEAK unsigned long boot_process_attempts;
FUXI_WEAK unsigned long boot_process_busy;
FUXI_WEAK unsigned long boot_process_capture;
FUXI_WEAK unsigned long boot_process_passes;
FUXI_WEAK unsigned long boot_process_rows;
FUXI_WEAK unsigned long boot_process_seen;
FUXI_WEAK unsigned long boot_process_snapshot;
FUXI_WEAK unsigned long boot_progress_exit_fault;
FUXI_WEAK unsigned long boot_progress_exit_reason;
FUXI_WEAK unsigned long boot_progress_throw_text;
FUXI_WEAK unsigned long boot_ui_trace_index;
FUXI_WEAK unsigned long boot_ui_trace_label;
FUXI_WEAK unsigned long boot_ui_trace_phase;
FUXI_WEAK unsigned long boot_ui_trace_ready;
FUXI_WEAK unsigned long boot_ui_trace_role_rows;
FUXI_WEAK unsigned long boot_ui_trace_rows;
FUXI_WEAK unsigned long boot_ui_trace_snapshot;
FUXI_WEAK unsigned long native_adreno_audit_attr;
FUXI_WEAK unsigned long native_adreno_audit_ticks;
FUXI_WEAK unsigned long native_adreno_cache_stats;
FUXI_WEAK unsigned long native_adreno_coherence;
FUXI_WEAK unsigned long native_adreno_reassert_ticks;
FUXI_WEAK unsigned long native_adreno_wc_audit;
FUXI_WEAK unsigned long native_adreno_wc_distrusted;
FUXI_WEAK unsigned long native_cpufreq_row;
FUXI_WEAK unsigned long native_cpufreq_stage;
FUXI_WEAK unsigned long native_data_persist_errors;
FUXI_WEAK unsigned long native_data_persist_first_lba;
FUXI_WEAK unsigned long native_data_persist_gpt;
FUXI_WEAK unsigned long native_data_persist_gpt_after;
FUXI_WEAK unsigned long native_data_persist_header;
FUXI_WEAK unsigned long native_data_persist_loaded;
FUXI_WEAK unsigned long native_data_persist_pages;
FUXI_WEAK unsigned long native_data_persist_present;
FUXI_WEAK unsigned long native_data_persist_state;
FUXI_WEAK unsigned long native_data_persist_syncs;
FUXI_WEAK unsigned long native_data_persist_writes;
FUXI_WEAK unsigned long native_gop_gpu_abandoned;
FUXI_WEAK unsigned long native_gop_gpu_completions;
FUXI_WEAK unsigned long native_gop_gpu_failures;
FUXI_WEAK unsigned long native_gop_gpu_offers;
FUXI_WEAK unsigned long native_hid_input_events;
FUXI_WEAK unsigned long native_hid_input_results;
FUXI_WEAK unsigned long native_legacy_client_calls;
FUXI_WEAK unsigned long native_legacy_client_class;
FUXI_WEAK unsigned long native_legacy_client_pid;
FUXI_WEAK unsigned long native_legacy_client_status;
FUXI_WEAK unsigned long native_legacy_client_type;
FUXI_WEAK unsigned long native_legacy_copy_bytes_last;
FUXI_WEAK unsigned long native_legacy_copy_bytes_sum;
FUXI_WEAK unsigned long native_legacy_copy_last;
FUXI_WEAK unsigned long native_legacy_copy_max;
FUXI_WEAK unsigned long native_legacy_copy_n;
FUXI_WEAK unsigned long native_legacy_copy_sum;
FUXI_WEAK unsigned long native_legacy_frame_color_counts;
FUXI_WEAK unsigned long native_legacy_frame_color_other;
FUXI_WEAK unsigned long native_legacy_frame_colors;
FUXI_WEAK unsigned long native_legacy_frame_count;
FUXI_WEAK unsigned long native_legacy_frame_kind;
FUXI_WEAK unsigned long native_legacy_frame_stats;
FUXI_WEAK unsigned long native_legacy_frame_time;
FUXI_WEAK unsigned long native_legacy_gop_bytes;
FUXI_WEAK unsigned long native_legacy_gop_physical;
FUXI_WEAK unsigned long native_legacy_gop_virtual;
FUXI_WEAK unsigned long native_legacy_gpu_fallbacks;
FUXI_WEAK unsigned long native_legacy_gpu_last_status;
FUXI_WEAK unsigned long native_legacy_guard_slot;
FUXI_WEAK unsigned long native_legacy_pm_callbacks;
FUXI_WEAK unsigned long native_legacy_pm_calls;
FUXI_WEAK unsigned long native_legacy_pm_stage;
FUXI_WEAK unsigned long native_legacy_prepare_attempts;
FUXI_WEAK unsigned long native_legacy_prepare_calls;
FUXI_WEAK unsigned long native_legacy_prepare_reason;
FUXI_WEAK unsigned long native_legacy_rej_class;
FUXI_WEAK unsigned long native_legacy_rej_options;
FUXI_WEAK unsigned long native_legacy_rej_reason;
FUXI_WEAK unsigned long native_legacy_rej_rects;
FUXI_WEAK unsigned long native_legacy_rej_size;
FUXI_WEAK unsigned long native_legacy_rej_state;
FUXI_WEAK unsigned long native_legacy_rej_surface;
FUXI_WEAK unsigned long native_legacy_rej_surfaces;
FUXI_WEAK unsigned long native_legacy_retirement_calls;
FUXI_WEAK unsigned long native_legacy_stage;
FUXI_WEAK unsigned long native_legacy_swap_accepted_count;
FUXI_WEAK unsigned long native_legacy_swap_rejected_count;
FUXI_WEAK unsigned long native_legacy_swap_validation_calls;
FUXI_WEAK unsigned long native_legacy_swap_validation_reason;
FUXI_WEAK unsigned long native_legacy_swap_validation_result;
FUXI_WEAK unsigned long native_legacy_transfer_bytes;
FUXI_WEAK unsigned long native_legacy_transfer_calls;
FUXI_WEAK unsigned long native_legacy_transfer_status;
FUXI_WEAK unsigned long native_ram_block_bytes;
FUXI_WEAK unsigned long native_ram_block_resident_bytes;
FUXI_WEAK unsigned long native_ram_block_sparse;
FUXI_WEAK unsigned long native_touch_count;
FUXI_WEAK unsigned long native_touch_ids;
FUXI_WEAK unsigned long native_touch_loop_step;
FUXI_WEAK unsigned long native_touch_rows;
FUXI_WEAK unsigned long native_touch_seq;
FUXI_WEAK unsigned long native_touch_stage_req;
FUXI_WEAK unsigned long native_touch_xs;
FUXI_WEAK unsigned long native_touch_ys;
FUXI_WEAK unsigned long native_ufs_matched;
FUXI_WEAK unsigned long native_ufs_probe_calls;
FUXI_WEAK unsigned long native_ufs_read_ticks;
FUXI_WEAK unsigned long native_ufs_root_failure;
FUXI_WEAK unsigned long native_ufs_root_step;
FUXI_WEAK unsigned long native_ufs_verify_ticks;
FUXI_WEAK unsigned long native_wi_count;
FUXI_WEAK unsigned long native_wi_log;

/* --- sheng kit weak imports (generated, all kit sources) -------------------- */
/* Every kit probe is a weak import; the kernel link still wants definitions.
 * The board has no sheng probes, so zeroed weak definitions stand in. */
FUXI_WEAK unsigned long boot_diag_errors;
FUXI_WEAK unsigned long boot_diag_files;
FUXI_WEAK unsigned long boot_diag_scan;
FUXI_WEAK unsigned long boot_diag_skipped;
FUXI_WEAK unsigned long boot_diag_stream;
FUXI_WEAK unsigned long boot_log_tick;
FUXI_WEAK unsigned long boot_process_attempts;
FUXI_WEAK unsigned long boot_process_busy;
FUXI_WEAK unsigned long boot_process_capture;
FUXI_WEAK unsigned long boot_process_passes;
FUXI_WEAK unsigned long boot_process_rows;
FUXI_WEAK unsigned long boot_process_seen;
FUXI_WEAK unsigned long boot_process_snapshot;
FUXI_WEAK unsigned long boot_progress_banner_rows;
FUXI_WEAK unsigned long boot_progress_banner_text;
FUXI_WEAK unsigned long boot_progress_cancel_scanout;
FUXI_WEAK unsigned long boot_progress_exit_fault;
FUXI_WEAK unsigned long boot_progress_exit_reason;
FUXI_WEAK unsigned long boot_progress_ext;
FUXI_WEAK unsigned long boot_progress_ext_wide;
FUXI_WEAK unsigned long boot_progress_page_text;
FUXI_WEAK unsigned long boot_progress_prepare_scanout;
FUXI_WEAK unsigned long boot_progress_profile_rows;
FUXI_WEAK unsigned long boot_progress_pulse_anchor;
FUXI_WEAK unsigned long boot_progress_spawn_rows;
FUXI_WEAK unsigned long boot_progress_stage;
FUXI_WEAK unsigned long boot_progress_tag;
FUXI_WEAK unsigned long boot_progress_throw_text;
FUXI_WEAK unsigned long boot_reset_bootloader;
FUXI_WEAK unsigned long boot_reset_mark_bootloader;
FUXI_WEAK unsigned long boot_reset_probe;
FUXI_WEAK unsigned long boot_reset_watchdog;
FUXI_WEAK unsigned long boot_ui_trace_begin;
FUXI_WEAK unsigned long boot_ui_trace_hot_rows;
FUXI_WEAK unsigned long boot_ui_trace_index;
FUXI_WEAK unsigned long boot_ui_trace_label;
FUXI_WEAK unsigned long boot_ui_trace_phase;
FUXI_WEAK unsigned long boot_ui_trace_publish;
FUXI_WEAK unsigned long boot_ui_trace_ready;
FUXI_WEAK unsigned long boot_ui_trace_role_peer;
FUXI_WEAK unsigned long boot_ui_trace_role_rows;
FUXI_WEAK unsigned long boot_ui_trace_rows;
FUXI_WEAK unsigned long boot_ui_trace_snapshot;
FUXI_WEAK unsigned long boot_ui_trace_task;
FUXI_WEAK unsigned long native_adreno_asker_record;
FUXI_WEAK unsigned long native_adreno_audit_attr;
FUXI_WEAK unsigned long native_adreno_audit_ticks;
FUXI_WEAK unsigned long native_adreno_cache_stats;
FUXI_WEAK unsigned long native_adreno_cached_read32;
FUXI_WEAK unsigned long native_adreno_client_log;
FUXI_WEAK unsigned long native_adreno_client_record;
FUXI_WEAK unsigned long native_adreno_client_stats;
FUXI_WEAK unsigned long native_adreno_client_text;
FUXI_WEAK unsigned long native_adreno_coherence;
FUXI_WEAK unsigned long native_adreno_coherent_skips;
FUXI_WEAK unsigned long native_adreno_dram_read32;
FUXI_WEAK unsigned long native_adreno_export_stats;
FUXI_WEAK unsigned long native_adreno_fence_phys;
FUXI_WEAK unsigned long native_adreno_fence_wait;
FUXI_WEAK unsigned long native_adreno_ib_log;
FUXI_WEAK unsigned long native_adreno_ib_log_count;
FUXI_WEAK unsigned long native_adreno_import_diag;
FUXI_WEAK unsigned long native_adreno_import_fail_offset;
FUXI_WEAK unsigned long native_adreno_import_fail_pa;
FUXI_WEAK unsigned long native_adreno_import_live;
FUXI_WEAK unsigned long native_adreno_import_persistent;
FUXI_WEAK unsigned long native_adreno_import_stage;
FUXI_WEAK unsigned long native_adreno_io_coherent;
FUXI_WEAK unsigned long native_adreno_map_fail;
FUXI_WEAK unsigned long native_adreno_metal_askers;
FUXI_WEAK unsigned long native_adreno_metal_rows;
FUXI_WEAK unsigned long native_adreno_method_stats;
FUXI_WEAK unsigned long native_adreno_mount_fail;
FUXI_WEAK unsigned long native_adreno_pool_stats;
FUXI_WEAK unsigned long native_adreno_pool_status;
FUXI_WEAK unsigned long native_adreno_pool_wc;
FUXI_WEAK unsigned long native_adreno_reassert_ticks;
FUXI_WEAK unsigned long native_adreno_ring_log;
FUXI_WEAK unsigned long native_adreno_ring_log_count;
FUXI_WEAK unsigned long native_adreno_view_diag;
FUXI_WEAK unsigned long native_adreno_vm_phase_us;
FUXI_WEAK unsigned long native_adreno_wait_outer;
FUXI_WEAK unsigned long native_adreno_wc_audit;
FUXI_WEAK unsigned long native_adreno_wc_distrusted;
FUXI_WEAK unsigned long native_adreno_window_overflow;
FUXI_WEAK unsigned long native_backlight_request;
FUXI_WEAK unsigned long native_backlight_stats;
FUXI_WEAK unsigned long native_buttons_stats;
FUXI_WEAK unsigned long native_cpufreq_row;
FUXI_WEAK unsigned long native_cpufreq_stage;
FUXI_WEAK unsigned long native_data_persist_errors;
FUXI_WEAK unsigned long native_data_persist_first_lba;
FUXI_WEAK unsigned long native_data_persist_gpt;
FUXI_WEAK unsigned long native_data_persist_gpt_after;
FUXI_WEAK unsigned long native_data_persist_header;
FUXI_WEAK unsigned long native_data_persist_loaded;
FUXI_WEAK unsigned long native_data_persist_pages;
FUXI_WEAK unsigned long native_data_persist_present;
FUXI_WEAK unsigned long native_data_persist_state;
FUXI_WEAK unsigned long native_data_persist_syncs;
FUXI_WEAK unsigned long native_data_persist_writes;
FUXI_WEAK unsigned long native_gop_gpu_completions;
FUXI_WEAK unsigned long native_gop_gpu_offers;
FUXI_WEAK unsigned long native_gop_virtual;
FUXI_WEAK unsigned long native_gop_wait_stats;
FUXI_WEAK unsigned long native_gpu_addon2_stage;
FUXI_WEAK unsigned long native_gpu_addon2_status;
FUXI_WEAK unsigned long native_gpu_addon3_stage;
FUXI_WEAK unsigned long native_gpu_addon3_status;
FUXI_WEAK unsigned long native_gpu_addon_error;
FUXI_WEAK unsigned long native_gpu_addon_failed;
FUXI_WEAK unsigned long native_gpu_addon_files;
FUXI_WEAK unsigned long native_gpu_addon_same;
FUXI_WEAK unsigned long native_gpu_addon_stage;
FUXI_WEAK unsigned long native_gpu_addon_status;
FUXI_WEAK unsigned long native_gpu_addon_written;
FUXI_WEAK unsigned long native_gpu_coherence_row;
FUXI_WEAK unsigned long native_gpu_idle_sleeps;
FUXI_WEAK unsigned long native_gpu_idle_spins;
FUXI_WEAK unsigned long native_gpu_perf_vote;
FUXI_WEAK unsigned long native_hid_input_command;
FUXI_WEAK unsigned long native_hid_input_events;
FUXI_WEAK unsigned long native_hid_input_results;
FUXI_WEAK unsigned long native_legacy_client_calls;
FUXI_WEAK unsigned long native_legacy_client_class;
FUXI_WEAK unsigned long native_legacy_client_pid;
FUXI_WEAK unsigned long native_legacy_client_status;
FUXI_WEAK unsigned long native_legacy_client_type;
FUXI_WEAK unsigned long native_legacy_clients_dump;
FUXI_WEAK unsigned long native_legacy_copy_bytes_last;
FUXI_WEAK unsigned long native_legacy_copy_bytes_sum;
FUXI_WEAK unsigned long native_legacy_copy_last;
FUXI_WEAK unsigned long native_legacy_copy_max;
FUXI_WEAK unsigned long native_legacy_copy_n;
FUXI_WEAK unsigned long native_legacy_copy_sum;
FUXI_WEAK unsigned long native_legacy_frame_color_counts;
FUXI_WEAK unsigned long native_legacy_frame_color_other;
FUXI_WEAK unsigned long native_legacy_frame_colors;
FUXI_WEAK unsigned long native_legacy_frame_count;
FUXI_WEAK unsigned long native_legacy_frame_kind;
FUXI_WEAK unsigned long native_legacy_frame_stats;
FUXI_WEAK unsigned long native_legacy_frame_time;
FUXI_WEAK unsigned long native_legacy_gop_bytes;
FUXI_WEAK unsigned long native_legacy_gop_physical;
FUXI_WEAK unsigned long native_legacy_gop_virtual;
FUXI_WEAK unsigned long native_legacy_gpu_fallbacks;
FUXI_WEAK unsigned long native_legacy_gpu_last_status;
FUXI_WEAK unsigned long native_legacy_guard_slot;
FUXI_WEAK unsigned long native_legacy_pm_callbacks;
FUXI_WEAK unsigned long native_legacy_pm_calls;
FUXI_WEAK unsigned long native_legacy_pm_stage;
FUXI_WEAK unsigned long native_legacy_prepare_attempts;
FUXI_WEAK unsigned long native_legacy_prepare_calls;
FUXI_WEAK unsigned long native_legacy_prepare_reason;
FUXI_WEAK unsigned long native_legacy_prepare_report;
FUXI_WEAK unsigned long native_legacy_properties_now;
FUXI_WEAK unsigned long native_legacy_rej_class;
FUXI_WEAK unsigned long native_legacy_rej_options;
FUXI_WEAK unsigned long native_legacy_rej_reason;
FUXI_WEAK unsigned long native_legacy_rej_rects;
FUXI_WEAK unsigned long native_legacy_rej_size;
FUXI_WEAK unsigned long native_legacy_rej_state;
FUXI_WEAK unsigned long native_legacy_rej_surface;
FUXI_WEAK unsigned long native_legacy_rej_surfaces;
FUXI_WEAK unsigned long native_legacy_retirement_calls;
FUXI_WEAK unsigned long native_legacy_stage;
FUXI_WEAK unsigned long native_legacy_state_words;
FUXI_WEAK unsigned long native_legacy_swap_accepted_count;
FUXI_WEAK unsigned long native_legacy_swap_rejected_count;
FUXI_WEAK unsigned long native_legacy_swap_timeline;
FUXI_WEAK unsigned long native_legacy_swap_validation_calls;
FUXI_WEAK unsigned long native_legacy_swap_validation_reason;
FUXI_WEAK unsigned long native_legacy_swap_validation_result;
FUXI_WEAK unsigned long native_legacy_transfer_bytes;
FUXI_WEAK unsigned long native_legacy_transfer_calls;
FUXI_WEAK unsigned long native_legacy_transfer_status;
FUXI_WEAK unsigned long native_ram_block_bytes;
FUXI_WEAK unsigned long native_ram_block_resident_bytes;
FUXI_WEAK unsigned long native_ram_block_sparse;
FUXI_WEAK unsigned long native_staged_apps_dirs;
FUXI_WEAK unsigned long native_staged_apps_error;
FUXI_WEAK unsigned long native_staged_apps_failed;
FUXI_WEAK unsigned long native_staged_apps_files;
FUXI_WEAK unsigned long native_staged_apps_mib;
FUXI_WEAK unsigned long native_staged_apps_path;
FUXI_WEAK unsigned long native_staged_apps_stage;
FUXI_WEAK unsigned long native_swipe_stats;
FUXI_WEAK unsigned long native_touch_count;
FUXI_WEAK unsigned long native_touch_edge_stats;
FUXI_WEAK unsigned long native_touch_extent;
FUXI_WEAK unsigned long native_touch_firmware;
FUXI_WEAK unsigned long native_touch_firmware_size;
FUXI_WEAK unsigned long native_touch_ids;
FUXI_WEAK unsigned long native_touch_loop_step;
FUXI_WEAK unsigned long native_touch_rows;
FUXI_WEAK unsigned long native_touch_seq;
FUXI_WEAK unsigned long native_touch_stage_req;
FUXI_WEAK unsigned long native_touch_stroke_count;
FUXI_WEAK unsigned long native_touch_strokes;
FUXI_WEAK unsigned long native_touch_xs;
FUXI_WEAK unsigned long native_touch_ys;
FUXI_WEAK unsigned long native_ufs_export_blocks;
FUXI_WEAK unsigned long native_ufs_export_write;
FUXI_WEAK unsigned long native_ufs_log_open;
FUXI_WEAK unsigned long native_ufs_log_sync;
FUXI_WEAK unsigned long native_ufs_log_write;
FUXI_WEAK unsigned long native_ufs_matched;
FUXI_WEAK unsigned long native_ufs_probe_calls;
FUXI_WEAK unsigned long native_ufs_read_ticks;
FUXI_WEAK unsigned long native_ufs_root_failure;
FUXI_WEAK unsigned long native_ufs_root_step;
FUXI_WEAK unsigned long native_ufs_store_gpt_check;
FUXI_WEAK unsigned long native_ufs_verify_ticks;
FUXI_WEAK unsigned long native_wi_count;
FUXI_WEAK unsigned long native_wi_log;
FUXI_WEAK unsigned long native_wifi_stats;
FUXI_WEAK unsigned long sheng_cpufreq_poll;

/* Kernel-side boot progress hooks; these live in XNU objects, not in the kits. */
FUXI_WEAK unsigned long native_owner_root_accepted;
FUXI_WEAK unsigned long native_virtio_read_failures;
FUXI_WEAK unsigned long native_virtio_read_requests;
FUXI_WEAK unsigned long native_virtio_ready;
FUXI_WEAK unsigned long native_virtio_verified_blocks;

/* Storage counters the progress page reads; the UFS driver is parked. */
FUXI_WEAK unsigned long native_ufs_block_failures;
FUXI_WEAK unsigned long native_ufs_block_reads;
FUXI_WEAK unsigned long native_ufs_blocks_published;
FUXI_WEAK unsigned long native_ufs_integrity_failures;
FUXI_WEAK unsigned long native_ufs_progress_text;
FUXI_WEAK unsigned long native_ufs_verified_blocks;

/* Startup progress ticker: the bar length is the number of startup callbacks run. */
#include <pexpert/pexpert.h>

extern vm_offset_t ml_static_ptovirt(vm_offset_t);

#define FUXI_TICK_X      8
#define FUXI_TICK_Y      8
#define FUXI_TICK_H      24
#define FUXI_TICK_MAX    900

void
fuxi_stage_tick(unsigned index)
{
	static unsigned last = ~0u;
	unsigned long base = (unsigned long)PE_state.video.v_baseAddr;
	unsigned long row;
	unsigned long virt;
	unsigned x, y, w;

	if (index == last || base == 0 || PE_state.video.v_depth != 32) {
		return;
	}
	last = index;

	virt = (unsigned long)ml_static_ptovirt((vm_offset_t)base);
	if (virt == 0) {
		virt = base;
	}
	row = PE_state.video.v_rowBytes;
	w = index < FUXI_TICK_MAX ? index : FUXI_TICK_MAX;

	for (y = FUXI_TICK_Y; y < FUXI_TICK_Y + FUXI_TICK_H; y++) {
		volatile unsigned int *p =
		    (volatile unsigned int *)(virt + (unsigned long)y * row);
		for (x = FUXI_TICK_X; x < FUXI_TICK_X + w; x++) {
			p[x] = 0x0000FF00u;
		}
		for (x = FUXI_TICK_X + w; x < FUXI_TICK_X + FUXI_TICK_MAX; x++) {
			p[x] = 0x00000000u;
		}
	}
}
